#include "str.h" // stdio.h, stdlib.h, string.h, stdbool.h

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

string* strCopy(string* original)
{
    string* result = str(original->data);
    return result;
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

size_t countStr(string* text, char* s)
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

stringArray* strArr(string* original, char* delim)
{
    stringArray* result = (stringArray*)malloc(sizeof(stringArray));
    if (!result) {
        perror("Unable to allocate memory for string array.\n");
        exit(EXIT_FAILURE);
    }
    size_t len = countStr(original, delim)+1;
    result->entries = (string**)malloc(sizeof(string*) * (len+1));
    char* token = strtok(original->data, delim);
    size_t current = 0;
    while (token != NULL) {
        string* temp = str(token);
        result->entries[current] = temp; 
        current++;
        token = strtok(NULL, delim);
    }
    result->entries[current] = NULL;
    result->length = len;
    return result;
}

size_t strArrFree(stringArray* arr)
{
    if (arr) {
        if (arr->entries) {
            for (size_t i = 0; i < arr->length; i++) {
                if (arr->entries[i]) {
                    free(arr->entries[i]->data);
                    arr->entries[i]->data = NULL;
                }
                free(arr->entries[i]);
                arr->entries[i] = NULL;
            }
            free(arr->entries);
            arr->entries = NULL;
        }
        free(arr);
        arr = NULL;
        return 1;
    }
    return 0;
}

void strArrDisplay(stringArray* arr)
{
    for (size_t i = 0; i < arr->length; i++) {
        puts(arr->entries[i]->data);
    }
}
