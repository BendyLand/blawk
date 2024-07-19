#include <unistd.h>
#include "regex.h" // "str.h" -> stdio.h, stdlib.h, string.h, stdbool.h
#include "utils.h" // "str.h" -> stdio.h, stdlib.h, string.h, stdbool.h

int main(void)
{
    string* test = str("Th[i-ubcd]nk");
    stringArray* res = expandCharClass(test);
    strArrDisplay(res);
    size_t f1 = strFree(test);
    size_t f2 = strArrFree(res);
    printf("String freed? %zu\nString array freed? %zu\n", f1, f2);
    sleep(10);
    return 0;
}
