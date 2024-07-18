#ifndef REGEX_H
#define REGEX_H

#include "str.h" // stdio.h, stdlib.h, string.h, stdbool.h

/**
 * Checks for valid regex.
 * @returns A boolean representing whether or not the given string contains a valid regex.
 */
bool isRegex(string* input);
stringArray* expandCharClass(string* original);

#endif