#include <stdio.h>
#include <string.h>
#include <ctype.h>  // For isdigit function
#include <stdlib.h>  // For exit function
#include "data.h"
#include "defs.h"


// convert token into AST operation
int arithop(int tok) {

    switch (tok) {
        case T_PLUS:
            return (A_ADD);
        case T_MINUS:
            return (A_SUBTRACT);
        case T_STAR:
            return (A_MULTIPLY);
        case T_SLASH:
            return (A_DIVIDE);
        default:
            fprintf(stderr, "unknown token in arithop() on line %d\n", Line);
            exit(1);
    }
}

// checks next token is an integer literal 
// builds an ast node to hold the literal value
static struct ASTnode *primary(void) {
    struct  ASTnode *n;

    // For an INTLIT token, make a leaf AST node for it
    // and scan in the next token. Otherwise, a syntax error
    // for any other token type
    switch(Token.token) {
        case T_INTLIT:
            n = mkastleaf(A_INTLIT, Token.intvalue);
            scan(&Token);
            return (n);
        default:
            fprintf(stderr, "syntax error on line %d\n", Line);
            exit(1);
    }
} 


// Return an AST tree where root is a binary operator
struct ASTnode *binexpr(void) {
    struct ASTnode *n, *left, *right;
    int nodetype;

    // Get integer literal on the left and fetch
    // next token at the same time
    left = primary();

    // if no tokens left return just left node
    if (Token.token == T_EOF) {
        return (left);
    }
    
    // convert token into a node type
    nodetype = arithop(Token.token);

    // Get next token
    scan(&Token);

    // Recursively get right hand tree
    right = binexpr();

    // make tree with both left and right subtrees
    n = mkastnode(nodetype, left, right, 0);

    return (n);
}