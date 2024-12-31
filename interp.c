#include <stdio.h>
#include <string.h>
#include <ctype.h>  // For isdigit function
#include <stdlib.h>  // For exit function
#include "Utils/data.h"
#include "Utils/defs.h"


// List of AST Operators
static char *ASTop[] = {"+", "-", "*", "/"};    

// Given an AST, interpret the 
// operators in it and return a final value
int interpretAST(struct ASTnode *n) {
    int leftval, rightval;

    // get left and right sub-tree values
    if (n->left) {
        leftval = interpretAST(n->left);
    }

    if (n->right) {
        rightval = interpretAST(n->right);
    }

    // Debug
    if (n->op == A_INTLIT) {
        printf("int %d\n", n->intvalue);
    }
    else {
        printf("%d %s %d\n", leftval, ASTop[n->op], rightval);
    }

    switch (n->op) {
        case A_ADD:
            return (leftval + rightval);
        case A_SUBTRACT:
            return (leftval - rightval);
        case A_DIVIDE:
            return (leftval / rightval);
        case A_MULTIPLY:
            return (leftval * rightval);
        case A_INTLIT:
            return (n->intvalue);
        default:
            fprintf(stderr, "Unknown AST operator %d\n", n->op);
            exit(1);
    }
}