#include "data.h"
#include "defs.h"

// Define the global variables
int Line = 1;      // Start from line 1
int Putback = '\n';   // No character put back initially
FILE *Infile = NULL; // Input file pointer, initialized to NULL
struct token Token; // Definition of Token
