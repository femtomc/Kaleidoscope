#include "parser.h"

std::map<char, int> BinopPrecedence;

int main() {
    // Install standard binary operators.
    // 1 is lowest precedence.
    BinopPrecedence['<'] = 10;
    BinopPrecedence['+'] = 20;
    BinopPrecedence['-'] = 20;
    BinopPrecedence['*'] = 40; // highest.

    // Prime the first token.
    fprintf(stderr, "(Kaleidoscope) > ");
    getNextToken();

    // Run the main "interpreter loop" now.
    MainLoop();

    return 0;
}
