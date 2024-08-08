#include <unistd.h>
#include "regex.h" // "str.h" -> stdio.h, stdlib.h, string.h, stdbool.h
#include "utils.h" // "str.h"

int main(void)
{
    string* test = str("/^Th[i-ubcd]nk$/");
    string* text = str("Think");
    printf("'%s' matches pattern? %d\n", text->data, isMatch(text, test));
    
    bool anchorTest = startsWithAnchor(test);
    bool anchorTest2 = endsWithAnchor(test);
    bool anchorTest3 = hasSurroundingAnchors(test);
    printf("Anchor test? %d\n", anchorTest);
    printf("Anchor test? %d\n", anchorTest2);
    printf("Anchor test? %d\n", anchorTest3);
    
    (void)strFree(test);
    (void)strFree(text);
    // puts("Run leaks now..."); sleep(10);
    return 0;
}
