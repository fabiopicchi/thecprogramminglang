#include <stdio.h>
#define TABSTOPS 4

void entab(int columns);

int main()
{
    entab(TABSTOPS);
    return 0;
}

void entab(int columns)
{
    int i = 0;
    int nblanks = 0;
    int c;

    while ((c=getchar()) != EOF) {
        if (c == ' ') {
            ++nblanks;
        } else  {
            // preference was given to '\t' where a single ' ' would suffice 
            // to avoid a special case
            while (nblanks > 0) {
                int tonext = (i/columns + 1) * columns - i;
                if (nblanks >= tonext) {
                    putchar('\t');
                    i = i + tonext;
                    nblanks = nblanks - tonext;
                } else {
                    putchar(' ');
                    ++i;
                    --nblanks;
                }
            }

            putchar(c);
            if (c == '\t') {
                int tonext = (i/columns + 1) * columns - i;
                i = i + tonext;
            } else if (c == '\n')
                i = 0;
            else
                ++i;
        }
    }
}

