#ifndef LIB_PARSER_H
#define LIB_PARSER_H

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

/// GetTokPrecedence - Get the precedence of the pending binary operator token.
int GetTokPrecedence();
void MainLoop();

#endif
