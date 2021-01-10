#ifndef INCLUDE_CODEGEN_H
#define INCLUDE_CODEGEN_H

#include "llvm/ADT/APFloat.h"
#include "llvm/ADT/STLExtras.h"
#include "llvm/IR/BasicBlock.h"
#include "llvm/IR/Constants.h"
#include "llvm/IR/DerivedTypes.h"
#include "llvm/IR/Function.h"
#include "llvm/IR/IRBuilder.h"
#include "llvm/IR/LLVMContext.h"
#include "llvm/IR/Module.h"
#include "llvm/IR/Type.h"
#include "llvm/IR/Verifier.h"

#include "ast.h"
#include "parser.h"

static std::unique_ptr<llvm::LLVMContext> Ctx;
static std::unique_ptr<llvm::IRBuilder<>> Builder;
static std::unique_ptr<llvm::Module> Mod;
static std::map<std::string, llvm::Value *> NamedValues;

static llvm::Value *LogErrorV(const char *Str) {
    LogError(Str);
    return nullptr;
}

void initializeModule();

#endif
