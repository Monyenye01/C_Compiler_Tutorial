#ifndef DEF_H
#define DEF_H

// Token structure
struct token {
    int token;
    int intvalue;
}; // Missing semicolon added here

// Tokens
enum {
    T_PLUS,
    T_MINUS,
    T_STAR,
    T_SLASH,
    T_INTLIT // Removed trailing comma
};
int scan(struct token *t);

#endif // DEF_H