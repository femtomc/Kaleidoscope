#include "codegen.h"
#include "ast.h"

Value *NumberExprAST::codegen() {
    return ConstantFP::get(Ctx, APFloat(Val));
}

Value *VariableExprAST::codegen() {
    Value *V = NamedValues[Name];
    if (!V) LogErrorV("Unknown variable name.");
    return V;
}

Value *BinaryExprAST::codegen() {
    Value *L = LHS->codegen();
    Value *R = RHS->codegen();
    if (!L || !R) return nullptr;
    switch (Op) {
        case '+':
            return Builder->CreateFAdd(L, R, "addtmp");
        case '-':
            return Builder->CreateFSub(L, R, "subtmp");
        case '*':
            return Builder->CreateFMul(L, R, "multmp");
        case '<':
            L = Builder->CreateFCmpULT(L, R, "cmptmp");
            return Builder->CreateUIToFP(L, Type::getDoubleTy(*Ctx), "booltmp");
        default:
            return LogErrorV("Invalid binary operator.");
    }
}

Value *CallExprAST::codegen() {
    // Look up the name in the global module table.
    Function *CalleeF = Mod->getFunction(Callee);
    if (!CalleeF)
        return LogErrorV("Unknown function referenced");

    // If argument mismatch error.
    if (CalleeF->arg_size() != Args.size())
        return LogErrorV("Incorrect # arguments passed");

    std::vector<Value *> ArgsV;
    for (unsigned i = 0, e = Args.size(); i != e; ++i) {
        ArgsV.push_back(Args[i]->codegen());
        if (!ArgsV.back())
            return nullptr;
    }

    return Builder->CreateCall(CalleeF, ArgsV, "calltmp");
}

Function *PrototypeAST::codegen() {
    // Make the function type:  double(double,double) etc.
    std::vector<Type *> Doubles(Args.size(), Type::getDoubleTy(*Ctx));
    FunctionType *FT =
        FunctionType::get(Type::getDoubleTy(*Ctx), Doubles, false);

    Function *F =
        Function::Create(FT, Function::ExternalLinkage, Name, Mod.get());

    // Set names for all arguments.
    unsigned Idx = 0;
    for (auto &Arg : F->args())
        Arg.setName(Args[Idx++]);

    return F;
}

Function *FunctionAST::codegen() {
    // First, check for an existing function from a previous 'extern' declaration.
    Function *Fn = Mod->getFunction(Proto->getName());

    if (!Fn)
        Fn = Proto->codegen();

    if (!Fn)
        return nullptr;

    // Create a new basic block to start insertion into.
    BasicBlock *BB = BasicBlock::Create(*Ctx, "entry", Fn);
    Builder->SetInsertPoint(BB);

    // Record the function arguments in the NamedValues map.
    NamedValues.clear();
    for (auto &Arg : Fn->args())
        NamedValues[std::string(Arg.getName())] = &Arg;

    if (Value *RetVal = Body->codegen()) {
        // Finish off the function.
        Builder->CreateRet(RetVal);

        // Validate the generated code, checking for consistency.
        verifyFunction(*Fn);

        return Fn;
    }

    // Error reading body, remove function.
    Fn->eraseFromParent();
    return nullptr;
}

/////
///// JIT Driver
/////

static void initializeModule() {
    Ctx = std::make_unique<LLVMContext>();
    Mod = std::make_unique<Module>("jit", *Ctx);
    Builder = std::make_unique<IRBuilder<>>(*Ctx);
}
