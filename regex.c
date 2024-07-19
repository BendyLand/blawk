
#include <stdbool.h>
#include "str.h" // stdio.h, string.h, stdlib.h

bool isRegex(string* input)
{
    return count(input, '/') == 2;
}

stringArray* expandCharClass(string* pattern)
{
    if (!contains(pattern, "[") || !contains(pattern, "]")) return strArr(pattern, "\n");
    size_t start = indexOf(pattern, "[");
    size_t end = indexOf(pattern, "]");
    string* firstHalf = substr(pattern, 0, start);
    string* secondHalf = substr(pattern, end+1, pattern->length);
    string* patternChars = substr(pattern, start+1, end);
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
