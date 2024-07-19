
#include <stdbool.h>
#include "str.h" // stdio.h, string.h, stdlib.h
#include "utils.h"

bool isRegex(string* input)
{
    return strCountChar(input, '/') == 2;
}

string* expandRange(string* chars)
{
    string* alphaNums = str("abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789");
    int idx = indexOfChar(chars, '-');
    string* result;
    if (idx > 0 && idx < chars->length-1) {
        int start = indexOfChar(alphaNums, chars->data[idx-1]);
        int end = indexOfChar(alphaNums, chars->data[idx+1]);
        result = substr(alphaNums, start, end+1);
    }
    else {
        result = chars;
    }
    (void)strFree(alphaNums);
    return result;
}

stringArray* expandCharClass(string* pattern)
{
    if (!strContainsChar(pattern, '[') || !strContainsChar(pattern, ']')) return strArr(pattern, "\n");
    size_t start = indexOfStr(pattern, "[");
    size_t end = indexOfStr(pattern, "]");
    string* firstHalf = substr(pattern, 0, start);
    string* secondHalf = substr(pattern, end+1, pattern->length);
    string* patternChars = substr(pattern, start+1, end);
    bool hasRange = strContainsChar(patternChars, '-');
    if (hasRange) {
        string* range = expandRange(patternChars);
        printf("Range: %s\n", range->data);
        //todo: create function to insert range chars back into original pattern
    }
    stringArray* result = NULL;
    for (size_t i = 0; i < patternChars->length; i++) {
        string* temp = str("");
        strAppend(temp, firstHalf->data);
        strAppendChar(temp, patternChars->data[i]); 
        strAppend(temp, secondHalf->data);
        if (!result) {
            result = strArr(temp, "\n");
        }
        else {
            strArrAppend(result, strCopy(temp));
        }
        strFree(temp);
    }
    strFree(firstHalf);
    strFree(secondHalf);
    strFree(patternChars);
    return result;
}
