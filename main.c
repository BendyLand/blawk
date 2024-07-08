#include "str.h"

int main(void)
{
    string* test = str("This is a test. ");
    puts(test->data);
    printf("Length: %zu\n", test->length);
    strAppend(test, "And this is another.");
    puts(test->data);
    printf("Length: %zu\n", test->length);
    strClear(test);
    printf("Cleared string: %s(EOF)\n", test->data);
    printf("Length: %zu\n", test->length);
    strFree(test);
    return 0;
}
