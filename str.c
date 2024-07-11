#include "str.h"

string* str(char* text)
{
    string* result = (string*)malloc(sizeof(string));
    if (!result) {
        perror("Unable to allocate memory for string struct.\n");
        exit(EXIT_FAILURE);
    }
    size_t len = strlen(text);
    result->data = (char*)malloc(len + 1);
    if (!result->data) {
        perror("Unable to allocate memory for string data\n");
        exit(EXIT_FAILURE);
    }
    strcpy(result->data, text);
    result->length = len;
    return result;
}

size_t strFree(string* str)
{
    if (str) {
        free(str->data);
        free(str);
        return 1;
    }
    return 0;
}

void strAppend(string* original, char* suffix)
{
    size_t newLen = original->length + strlen(suffix); 
    char* newData = (char*)realloc(original->data, newLen + 1);
    if (!newData) {
        perror("Unable to reallocate memory for new string.\n");
        exit(EXIT_FAILURE);
    }
    strcat(newData, suffix);
    original->data = newData;
    original->length = newLen;
}

void strClear(string* original)
{
    original->data[0] = '\0';
    char* newData = (char*)realloc(original->data, 1);
    if (!newData) {
        perror("Unable to reallocate memory for cleared string.\n");
        exit(EXIT_FAILURE);
    }
    original->data = newData;
    original->length = 0;
}

int indexOf(string* text, char* pattern)
{
    int result = -1;
    size_t len = strlen(pattern);
    for (size_t i = 0; i < text->length; i++) {
        if (text->data[i] == pattern[0]) {
            size_t j = 0;
            while (text->data[i+j] == pattern[j]) j++; 
            if (j == len) result = i;
        }
    }
    return result;
}

bool contains(string* text, char* pattern)
{
    size_t len = strlen(pattern);
    for (size_t i = 0; i < text->length; i++) {
        if (text->data[i] == pattern[0]) {
            size_t j = 0;
            while (text->data[i+j] == pattern[j]) j++; 
            if (j == len) return true;
        }
    }
    return false;
}

size_t count(string* text, char c)
{
    size_t result = 0;
    for (size_t i = 0; i < text->length; i++) {
        if (text->data[i] == c) result++;
    }
    return result;
}
