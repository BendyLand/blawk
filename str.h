#pragma once

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

typedef struct 
{
    char* data;
    size_t length;
} string;

typedef struct
{
    string** entries;
    size_t length;
} stringArray;

/**
 * Constructor for the string type.
 * @param text The text to be saved in the string type.
 * @return A string* of the text passed in and its length.
 */  
string* str(char* text);

string* strCopy(string* original);

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
void strAppendChar(string* original, char c);

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
 * @param text The string to look through. 
 * @param c The letter to look for within the string.
 * @returns The number of times the letter is found in the text.  
 */
size_t count(string* text, char c);

/**
 * Counts the numver of times a substring is found in the source text.
 * @param text The string to look through.
 * @param s The substring to look for within the string.
 * @returns The number of times the substring is found in the text.
 */
size_t countStr(string* text, char* s);

/**
 * Constructor function for the stringArray* type.
 * @param original The string* to split into an array.
 * @param delim The delimiter to split the string by.
 * @returns A stringArray* of the split string.
 */
stringArray* strArr(string* original, char* delim);

/**
 * Destructor function for the stringArray* type.
 * @param arr The stringArray* to free.
 * returns 1 if the array was successfully freed, 0 otherwise. 
 */
size_t strArrFree(stringArray* arr);

/**
 * Prints all of the entries in the given string array.
 * @param arr The stringArray* to print out.
 */
void strArrDisplay(stringArray* arr);

/**
 * Appends a new element to the provided stringArray* in place.
 * @param original The string array to add on to.
 * @param item The new element to add to the array.
 */
void strArrAppend(stringArray* original, string* item);

/**
 * Creates a new string by joining the given string array by the delimiter.
 * @param arr The stringArray to join.
 * @param delim The char* delimiter to join the array by.
 * @returns A new string made from the array data.
 */
string* strArrJoin(stringArray* arr, char* delim);
