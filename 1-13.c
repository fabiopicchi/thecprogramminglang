#include <stdio.h>
#define INWORD 1
#define OUTWORD 0
#define MAXLEN 1000

int main()
{
    int c;
    int histogram[MAXLEN];
    int nc = 0;
    int maxhist = 0;
    int state = OUTWORD;

    for (int i = 0; i < MAXLEN; i++)
        histogram[i] = 0;

    while ((c = getchar()) != EOF) {
        if (c != ' ' && c != '\n' && c != '\t') {
            state = INWORD;
            ++nc;
        } else if (state == INWORD) {
            state = OUTWORD;
            ++histogram[nc];
            if (histogram[nc] > maxhist)
                maxhist = histogram[nc];
            nc = 0;
        }
    }
    
    // horizontal histogram
    // for (int i = 0; i < MAXLEN; i++) {
    //     if (histogram[i] > 0) {
    //         printf("%d ", i);
    //         for (int j = 0; j < histogram[i]; j++)
    //             putchar('=');
    //         putchar('\n');
    //     }
    // }

    for (int i = maxhist - 1; i >= 0; i--) {
        for (int j = 0; j < MAXLEN; j++) {
            if (histogram[j] > 0) {
                if (histogram[j] > i)
                    printf(" || ");
                else
                    printf("    ");

            }
        }
        putchar('\n');
    }
    
    // subtitles
    for (int i = 0; i < MAXLEN; i++) {
        if (histogram[i] > 0) {
            if (i < 10) {
                printf("  %d ", i);
            } else if (i < 100) {
                printf(" %d ", i);
            } else {
                printf(" %d", i);
            }
        }
    }
}
