#include "Utils/data.h"
#include "Utils/defs.h"
#include <stdio.h>
#include <stdlib.h>


// static void scanfile() {
//     struct token T;

//     // List of printable tokens
//     char *tokstr[] = { "+", "-", "*", "/", "intlit" }; 

//     while (scan(&T)) {
//         printf("Token %s", tokstr[T.token]);
//         if (T.token == T_INTLIT) {
//             printf(", value %d", T.intvalue);
//         }
//         printf("\n");
//     }
// }

int main(int argc, char *argv[]) {
    // init();
    struct ASTnode *n;
    Infile = fopen(argv[1], "r");

    // scanfile();
    // exit(0);
    scan(&Token); // get first token from input
    n = binexpr(); // parse expression in the file
    printf("%d\n", interpretAST(n)); // calculate final result
    return 0;
}