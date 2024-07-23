#pragma once

#include "str.h" // stdio.h, stdlib.h, string.h, stdbool.h

/**
 * Checks the given string for the presence of a specific character.
 * @param haystack The string to look through.
 * @param needle The character to look for.
 * @returns True if the character is found in the string, false otherwise.
 */
bool strContainsChar(string* haystack, char needle);

/**
 * Checks the given string for the presence of a certain substring.
 * @param haystack The string to look through.
 * @param needle The string data to look for.
 * @returns True if the substring data is found in the string, false otherwise.
 */
bool strContainsStr(string* haystack, char* needle);

/**
 * Counts the number of occurrences of a specific character in a given string.
 * @param text The string to look through.
 * @param c The character to count in the string.
 * @returns The number of times `c` was found in the string.
 */
size_t strCountChar(string* text, char c);

/**
 * Counts the number of occurrences of a substring in a given string.
 * @param text The string to look through.
 * @param s The substring to count in the string.
 * @returns The number of times `s` was found in the string.
 */
size_t strCountStr(string* text, char* s);

/**
 * Creates a substring using the characters from the indeces `start` to `end` in the original string.
 * @param start The index to start the substring from.
 * @param end The index to end the substring (exclusive).
 */
string* substr(string* original, size_t start, size_t end);

/**
 * Finds the index of given substring data.
 * @param text The text to search through.
 * @param pattern The substring to look for.
 * @returns The first index of the substring, if it is found. -1 otherwise.
 */
int indexOfStr(string* text, char* pattern);

/**
 * Finds the index of a given character.
 * @param text The text to search through.
 * @param c The character to look for.
 * @returns The first index of the character, if it is found. -1 otherwise.
 */
int indexOfChar(string* text, char c);
