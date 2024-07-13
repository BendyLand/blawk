#include <unistd.h>
#include "regex.h" // "str.h" -> stdio.h, stdlib.h, string.h, stdbool.h
#include "str.h"

int main(void)
{
    string* test = str("This is a test.");
    stringArray* testArr = strArr(test, " ");
    strArrDisplay(testArr);
    size_t f1 = strFree(test);
    size_t f2 = strArrFree(testArr);
    // sleep(10);
    return 0;
}
