#ifndef INCLUDE_PARSER_H
#define INCLUDE_PARSER_H

#include "ast.h"
using namespace ast;
#include "token.h"
#include <map>
#include "lexer.h"

extern int CurTok;
int getNextToken();

/// BinopPrecedence - This holds the precedence for each binary operator that is
/// defined.
extern std::map<char, int> BinopPrecedence;

/// LogError* - These are little helper functions for error handling.
std::unique_ptr<ExprAST> LogError(const char *Str);
std::unique_ptr<PrototypeAST> LogErrorP(const char *Str);

/// GetTokPrecedence - Get the precedence of the pending binary operator token.
int GetTokPrecedence();
void MainLoop();

#endif
