#include <stdio.h>

int main()
{
    int c;
    int nb = 0;
    int nt = 0;
    int nl = 0;

    while ((c = getchar()) != EOF) {
        if (c == ' ')
            ++nb;
        if (c == '\t')
            ++nt;
        if (c == '\n')
            ++nl;
    }

    printf("%d %d %d", nb, nt, nl);
}
