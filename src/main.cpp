#include "parser.h"
#include "codegen.h"

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

    // Create module to hold IR code.
    initializeModule();

    // Run the main "interpreter loop" now.
    MainLoop();
   
    // Dump generated code.
    Mod->print(errs(), nullptr);

    return 0;
}
