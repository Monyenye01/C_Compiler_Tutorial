#ifndef DATA_H
#define DATA_H

#include <stdio.h> // For FILE

// Define the global variables
extern int Line;  // Start from line 1
extern int Putback;  // No character put back initially
extern FILE *Infile;  // Input file pointer, initialized to NULL
extern struct token Token; // Has the most recent token scanned in from the input


#endif // DATA_H
