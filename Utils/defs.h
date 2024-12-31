#ifndef DEF_H
#define DEF_H

// Token structure
struct token {
    int token;
    int intvalue;
}; // Missing semicolon added here

// Tokens
enum {
    T_EOF,
    T_PLUS,
    T_MINUS,
    T_STAR,
    T_SLASH,
    T_INTLIT // Removed trailing comma
};

// AST node types
enum {
    A_ADD,
    A_SUBTRACT,
    A_MULTIPLY,
    A_DIVIDE,
    A_INTLIT
};


// Abstract Syntax Tree Structure
// AST node with no sub-tree children has intvalue with value
struct ASTnode {
    int op; // "Operation" to be performed on this tree
    struct ASTnode *left;  // left child tree
    struct ASTnode *right; // right child tree
    int intvalue;  // For A_INTLIT, the integer value
};


int scan(struct token *t);
struct ASTnode *binexpr(void);
int interpretAST(struct ASTnode *n);
struct  ASTnode *mkastleaf(int op, int intvalue);
struct ASTnode *mkastunary(int op, struct ASTnode *left, int intvalue);
struct ASTnode *mkastnode(int op,
                            struct ASTnode *left,
                            struct ASTnode *right,
                            int intvalue);
#endif // DEF_H