#include <stdio.h>
#define MAXCHARS 128

int main()
{
    int c;
    int histogram[MAXCHARS];
    int maxhist = 0;

    for (int i = 0; i < MAXCHARS; i++)
        histogram[i] = 0;

    while ((c = getchar()) != EOF) {
        ++histogram[c];
        if (histogram[c] > maxhist)
            maxhist = histogram[c];
    }
    
    for (int i = 0; i < MAXCHARS; i++) {
        if (histogram[i] > 0) {
            if (i == '\n') 
                printf("\\n ");
            else if (i == '\t') 
                printf("\\t ");
            else if (i == ' ') 
                printf("\\s ");
            else
                printf("%c ", i);
            for (int j = 0; j < histogram[i]; j++)
                putchar('=');
            putchar('\n');
        }
    }

    // vertical histogram
    // for (int i = maxhist - 1; i >= 0; i--) {
    //     for (int j = 0; j < MAXCHARS; j++) {
    //         if (histogram[j] > 0) {
    //             if (histogram[j] > i)
    //                 printf(" || ");
    //             else
    //                 printf("    ");

    //         }
    //     }
    //     putchar('\n');
    // }
    // 
    // // subtitles
    // for (int i = 0; i < MAXCHARS; i++) {
    //     if (histogram[i] > 0) {
    //         if (i == '\n') 
    //             printf(" \\n ");
    //         else if (i == '\t') 
    //             printf(" \\t ");
    //         else if (i == ' ') 
    //             printf(" \\s ");
    //         else
    //             printf("  %c ", i);
    //     }
    // }
}
