#include "codegen.h"

llvm::Value *ast::NumberExprAST::codegen() {
    return llvm::ConstantFP::get(*Ctx, llvm::APFloat(Val));
}

llvm::Value *ast::VariableExprAST::codegen() {
    llvm::Value *V = NamedValues[Name];
    if (!V) LogErrorV("Unknown variable name.");
    return V;
}

llvm::Value *ast::BinaryExprAST::codegen() {
    llvm::Value *L = LHS->codegen();
    llvm::Value *R = RHS->codegen();
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
            return Builder->CreateUIToFP(L, llvm::Type::getDoubleTy(*Ctx), "booltmp");
        default:
            return LogErrorV("Invalid binary operator.");
    }
}

llvm::Value *ast::CallExprAST::codegen() {
    // Look up the name in the global module table.
    llvm::Function *CalleeF = Mod->getFunction(Callee);
    if (!CalleeF)
        return LogErrorV("Unknown function referenced");

    // If argument mismatch error.
    if (CalleeF->arg_size() != Args.size())
        return LogErrorV("Incorrect # arguments passed");

    std::vector<llvm::Value *> ArgsV;
    for (unsigned i = 0, e = Args.size(); i != e; ++i) {
        ArgsV.push_back(Args[i]->codegen());
        if (!ArgsV.back())
            return nullptr;
    }

    return Builder->CreateCall(CalleeF, ArgsV, "calltmp");
}

llvm::Function *ast::PrototypeAST::codegen() {
    // Make the function type:  double(double,double) etc.
    std::vector<llvm::Type *> Doubles(Args.size(), llvm::Type::getDoubleTy(*Ctx));
    llvm::FunctionType *FT =
        llvm::FunctionType::get(llvm::Type::getDoubleTy(*Ctx), Doubles, false);

    llvm::Function *F =
        llvm::Function::Create(FT, llvm::Function::ExternalLinkage, Name, Mod.get());

    // Set names for all arguments.
    unsigned Idx = 0;
    for (auto &Arg : F->args())
        Arg.setName(Args[Idx++]);

    return F;
}

llvm::Function *ast::FunctionAST::codegen() {
    // First, check for an existing function from a previous 'extern' declaration.
    llvm::Function *Fn = Mod->getFunction(Proto->getName());

    if (!Fn)
        Fn = Proto->codegen();

    if (!Fn)
        return nullptr;

    // Create a new basic block to start insertion into.
    llvm::BasicBlock *BB = llvm::BasicBlock::Create(*Ctx, "entry", Fn);
    Builder->SetInsertPoint(BB);

    // Record the function arguments in the NamedValues map.
    NamedValues.clear();
    for (auto &Arg : Fn->args())
        NamedValues[std::string(Arg.getName())] = &Arg;

    if (llvm::Value *RetVal = Body->codegen()) {
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

void initializeModule() {
    Ctx = std::make_unique<llvm::LLVMContext>();
    Mod = std::make_unique<llvm::Module>("jit", *Ctx);
    Builder = std::make_unique<llvm::IRBuilder<>>(*Ctx);
}
