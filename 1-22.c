// getline was added to the POSIX standard in 2008
// two line below were added to avoid conflict in the getline implementation
#undef _POSIX_C_SOURCE
#define _POSIX_C_SOURCE 200112L

#include <stdio.h>
#define NCOLUMNS 100
#define MAXLINE 1000
#define INWORD 1
#define OUTWORD 0

void fold(int columns);
int getline(char  line[], int maxline);

int main()
{
    fold(NCOLUMNS);
    return 0;
}

void fold(int columns)
{
    int i, j, linelen, state, ifold;
    char line[MAXLINE];
    
    while ((linelen = getline(line, MAXLINE)) > 0) {
        i = 0;
        j = 0;
        ifold = 0;
        state = OUTWORD;
        while (i < linelen && i < MAXLINE) {
            if (line[i] != ' ' && line[i] != '\n' && line[i] != '\t' && line[i] != '\0')
                state = INWORD;
            else if (state == INWORD) {
                state = OUTWORD;
                int wordlen = i - ifold;
                if (j + wordlen > columns) {
                    j = 0;
                    // check for edge case when word has more than ncolumns characters
                    int nlines = wordlen / columns;
                    
                    putchar('\n');
                    // skip the first blank character of this section
                    // as it is being swaped for a '\n' for the fold operation
                    ++ifold;
                }
                for (int k = ifold; k < i; ++k) {
                    putchar(line[k]);
                    ++j;
                }
                ifold = i;
            } 
            ++i;
        }
    }
    putchar('\n');
}

int getline(char s[], int lim)
{
    int c = 0;
    int i;

    for (i=0; (c=getchar())!=EOF && c!='\n'; ++i)
        if (i < lim-1)
            s[i] = (char)c;

    if (c=='\n') {
        if (i < lim-1)
            s[i] = (char)c;
        ++i;
    }

    if (i >= lim-1)
        s[lim-1] = '\0';
    else
        s[i] = '\0';
    return i;
}


