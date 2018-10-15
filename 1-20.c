#include <stdio.h>
#define TABSTOPS 4

void detab(int columns);

int main()
{
    detab(TABSTOPS);
    return 0;
}

// the number 'n' of columns should be a parameter
// to retain the generality of the function making
// it reusable in other contexts
void detab(int columns)
{
    int i = 0;
    int c;

    while ((c=getchar()) != EOF) {
        if (c == '\t') {
            int next = (i/columns + 1) * columns;
            for (int j = i; j < next; j++) {
                putchar(' ');
                ++i;
            }
        } else {
            putchar(c);
            if (c == '\n')
                i = 0;
            else
                ++i;
        }
    }
}

