#ifndef STR_H
#define STR_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

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

/**
 * Appends the suffix to the original string, in place.
 * @param original The base string* to add onto.
 * @param suffix The additional characters to add onto the base string.
 */
void strAppend(string* original, char* suffix);

/**
 * Removes any characters from the string, in place.
 * @param original The string to clear.
 */
void strClear(string* original);

/**
 * Finds the index of the matching substring.
 * @param haystack The string to look through.
 * @param needle The pattern to look for within the larger string.
 * @returns The index of the matching pattern, or -1 if the pattern wasn't found.
 */
int indexOf(string* haystack, char* needle);

/**
 * Checks a string for the presence of a substring.
 * @param haystack The string to look through.
 * @param needle The pattern to look for within the larger string.
 * @returns True if the pattern is found, otherwise false.
 */
bool contains(string* haystack, char* needle);

/**
 * Counts the number of times a letter is found in the source text.
 * @param text The string the look through. 
 * @param letter The letter to look for within the string.
 * @returns The number of times the letter is found in the string.  
 */
size_t count(string* text, char letter);

#endif