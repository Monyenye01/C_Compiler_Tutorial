#include <stdio.h>
#include <string.h>
#include <ctype.h>  // For isdigit function
#include <stdlib.h>  // For exit function
#include "data.h"
#include "defs.h"

// Forward declarations
static int scanint(int c);
static int chrpos(char *s, int c);

// Holds the functions of the Lexical Scanner

// Get the next character from the input file
static int next(void) {
    int c;

    if (Putback) {  // Use the character put back if there is one
        c = Putback;
        Putback = 0;
        return c;
    }

    c = fgetc(Infile); // Read from input file
    if ('\n' == c) {
        Line++; // Increment line count if next line
    }
    return c;
}

// Put back an unwanted character
static void putback(int c) {
    Putback = c;
}

// Function to ignore whitespace to get the next character
static int skip(void) {
    int c;

    c = next();

    while (' ' == c || '\t' == c || '\n' == c || '\r' == c || '\f' == c) {
        // Get next character
        c = next();
    }

    return (c);
}

// Scan and return the next token found in the input
// Return 1 if token valid, 0 if no tokens left
int scan(struct token *t) {
    int c;

    // Skip whitespace
    c = skip();

    // Determine token based on the input character
    switch(c) {
        case EOF:
            t->token = T_EOF;
            return (0);
        case '+':
            t->token = T_PLUS;
            break;
        case '-':
            t->token = T_MINUS;
            break;
        case '*':
            t->token = T_STAR;
            break;
        case '/':
            t->token = T_SLASH;
            break;
        default:
            // If it's a digit, scan the literal integer value
            if (isdigit(c)) {
                t->intvalue = scanint(c);
                t->token = T_INTLIT;
                break;
            }

            printf("Unrecognized character %c on line %d\n", c, Line);
            exit(1);
    }

    // Found token
    return (1);
}

// Construct integer literal value from input file
static int scanint(int c) {
    int k, val = 0;

    // Convert each character into an int value
    while ((k = chrpos("0123456789", c)) >= 0) {
        val = val * 10 + k;
        c = next();
    }

    // Got to non-integer character, put it back
    putback(c); // Put back in input stream to be consumed later
    return val;
}

// Return position of character in string or -1 if c not found
static int chrpos(char *s, int c) {
    char *p;

    p = strchr(s, c);

    return (p ? p - s : -1);
}
