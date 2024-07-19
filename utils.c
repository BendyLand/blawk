#include "utils.h"

bool strContainsChar(string* haystack, char needle)
{
    for (size_t i = 0; i < haystack->length; i++) {
        if (haystack->data[i] == needle) return true;
    }
    return false;
}

bool strContainsStr(string* haystack, string* needle)
{
    for (size_t i = 0; i < haystack->length; i++) {
        size_t j = 0; 
        if (haystack->data[i] == needle->data[0]) {
            while (haystack->data[i+j] == needle->data[j]) {
                j++;
                if (i + j == haystack->length) break;
            }
            if (j == needle->length) return true;
        }
    }
    return false;
}
