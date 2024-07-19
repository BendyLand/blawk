#include "utils.h"

bool strContainsChar(string* haystack, char needle)
{
    for (size_t i = 0; i < haystack->length; i++) {
        if (haystack->data[i] == needle) return true;
    }
    return false;
}

bool strContainsStr(string* haystack, char* needle)
{
    size_t len = strlen(needle);
    for (size_t i = 0; i < haystack->length; i++) {
        size_t j = 0; 
        if (haystack->data[i] == needle[0]) {
            while (haystack->data[i+j] == needle[j]) {
                j++;
                if (i + j == haystack->length) break;
            }
            if (j == len) return true;
        }
    }
    return false;
}

size_t strCountChar(string* text, char c)
{
    size_t result = 0;
    for (size_t i = 0; i < text->length; i++) {
        if (text->data[i] == c) result++;
    }
    return result;
}

size_t strCountStr(string* text, char* s)
{
    size_t result = 0;
    for (size_t i = 0; i < text->length; i++) {
        if (text->data[i] == s[0]) {
            size_t j = 0;
            while (text->data[i+j] == s[j]) j++;
            if (j == strlen(s)) result++;
        }
    }
    return result;
}

string* substr(string* original, size_t start, size_t end)
{
    size_t len = end - start + 1;
    char temp[len];
    size_t current = 0;
    for (size_t i = 0; i < original->length; i++) {
        if (i >= start && i < end) {
            temp[current] = original->data[i];
            current++;
        }
    }
    temp[current] = '\0';
    return str(temp);
}

int indexOfChar(string* text, char c)
{
    int result = -1;
    for (size_t i = 0; i < text->length; i++) {
        if (text->data[i] == c) {
            result = (int)i;
        }
    }
    return result;
}

int indexOfStr(string* text, char* pattern)
{
    int result = -1;
    size_t len = strlen(pattern);
    for (size_t i = 0; i < text->length; i++) {
        if (text->data[i] == pattern[0]) {
            size_t j = 0;
            while (text->data[i+j] == pattern[j]) j++;
            if (j == len) result = (int)i;
        }
    }
    return result;
}
