#pragma once

#include "str.h" // stdio.h, stdlib.h, string.h, stdbool.h

/**
 * Checks for valid regex.
 * @returns A boolean representing whether or not the given string contains a valid regex.
 */
bool isRegex(string* input);
bool isMatch(string* text, string* pattern);
string* extractPattern(string* pattern);
stringArray* expandCharClass(string* original);
bool startsWithAnchor(string* input);
bool endsWithAnchor(string* input);
bool hasSurroundingAnchors(string* input);
