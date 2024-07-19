#ifndef UTILS_H
#define UTILS_H

#include <stdio.h>
#include <stdbool.h>
#include "str.h"

bool strContainsChar(string* haystack, char needle);
bool strContainsStr(string* haystack, char* needle);
size_t strCountChar(string* text, char c);
size_t strCountStr(string* text, char* s);
string* substr(string* original, size_t start, size_t end);
int indexOfStr(string* text, char* pattern);
int indexOfChar(string* text, char c);

#endif