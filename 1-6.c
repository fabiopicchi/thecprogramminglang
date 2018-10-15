#include <stdio.h>

int main()
{
    int c = getchar();
    while (c != EOF) {
        printf("%d ", c != EOF);
        c = getchar();
    }

    printf("%d\n", c != EOF);
}

