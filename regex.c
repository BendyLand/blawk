#include <stdbool.h>
#include "str.h" // stdio.h, string.h, stdlib.h
#include "utils.h" // "str.h"

bool isRegex(string* input)
{
    return strCountChar(input, '/') == 2;
}

string* extractPattern(string* pattern)
{
    if (!isRegex(pattern)) return str("");
    size_t start = indexOfChar(pattern, '/');
    string* temp = substr(pattern, start+1, pattern->length);
    size_t end = indexOfChar(temp, '/') + (pattern->length - temp->length);
    (void)strFree(temp);
    string* result = substr(pattern, start+1, end);
    return result;
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
    if (chars->length > 3) {
        if (idx - 1 == 0) {
            string* temp = substr(chars, idx+2, chars->length);
            strAppend(result, temp->data);
            (void)strFree(temp);
        }
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
        (void)strFree(patternChars);
        patternChars = range;
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
        (void)strFree(temp);
    }
    (void)strFree(firstHalf);
    (void)strFree(secondHalf);
    (void)strFree(patternChars);
    return result;
}

bool isMatch(string* text, string* pattern)
{
    string* patternChars = extractPattern(pattern);
    stringArray* patterns = expandCharClass(patternChars);
    for (size_t i = 0; i < patterns->length; i++) {
        if (strcmp(text->data, patterns->entries[i]->data) == 0) {
            strArrFree(patterns);
            strFree(patternChars);
            return true;
        }
    }
    strArrFree(patterns);
    strFree(patternChars);
    return false;
}
