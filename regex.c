#include "str.h" // stdio.h, string.h, stdlib.h
#include <stdbool.h>

bool isRegex(string* input)
{
    return count(input, '/') == 2;
}

