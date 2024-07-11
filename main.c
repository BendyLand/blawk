#include <unistd.h>
#include "regex.h" // "str.h" -> stdio.h, stdlib.h, string.h, stdbool.h

int main(void)
{
    string* test = str("This is a test. ");
    strAppend(test, "And this is another.");
    string* regTest = str("/test/");
    bool test1 = isRegex(test);
    bool test2 = isRegex(regTest);
    printf("This example is a valid regex? %d\n", test1);
    printf("This example is a valid regex? %d\n", test2);
    strClear(test);
    strFree(test);
    strFree(regTest);
    // sleep(10);
    return 0;
}
