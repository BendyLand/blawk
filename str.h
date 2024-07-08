#ifndef STR_H
#define STR_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct 
{
    char* data;
    size_t length;
} string;

/**
 * Constructor for the string type.
 * @param text The text to be saved in the string type.
 * @return A string* of the text passed in and its length.
 */  
string* str(char* text);

/** 
 * Destructor for the string type.
 * @param str The string* to be freed.
 * @returns 1 if the string is successfully freed, 0 otherwise.
 */
size_t strFree(string* str);

void strAppend(string* original, char* suffix);
void strClear(string* original);


#endif