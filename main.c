#include <unistd.h>
#include "regex.h" // "str.h" -> stdio.h, stdlib.h, string.h, stdbool.h
#include "utils.h" // "str.h" 

int main(void)
{
    string* test = str("/Th[i-ubcd]nk/");
    string* pattern = extractPattern(test);
    puts(pattern->data);
    string* text = str("Thank");
    printf("'%s' matches pattern? %d\n", text->data, isMatch(text, test));
    (void)strFree(test);
    (void)strFree(text);
    (void)strFree(pattern);
    // puts("Run leaks now..."); sleep(10);
    return 0;
}
