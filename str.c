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
        perror("Unable to allocate memory for temporary string.\n");
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
    original->data = newData;
    original->length = 0;
}
