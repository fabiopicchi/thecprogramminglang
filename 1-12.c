#include <stdio.h>
#define INWORD 1
#define OUTWORD 0

int main()
{
    int c;
    int state = OUTWORD;

    while ((c = getchar()) != EOF) {
        if (c != ' ' && c != '\n' && c != '\t') {
            state = INWORD;
            putchar(c);
        } else if (state == INWORD) {
            state = OUTWORD;
            putchar('\n');
        }
    }
}
