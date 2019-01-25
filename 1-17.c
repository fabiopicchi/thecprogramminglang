// getline was added to the POSIX standard in 2008
// two line below were added to avoid conflict in the getline implementation
#undef _POSIX_C_SOURCE
#define _POSIX_C_SOURCE 200112L

#include <stdio.h>
#define MAXLINE 1000
#define TARGETLEN 80

int getline(char  line[], int maxline);
void copy(char to[], char from[]);

int main()
{
    int len;
    char line[MAXLINE];

    while ((len = getline(line, MAXLINE)) > 0)
        if (len > TARGETLEN) {
            printf("%s\n", line);
        }

    return 0;
}

int getline(char s[], int lim)
{
    int c = 0;
    int i;

    for (i = 0; (c=getchar())!=EOF && c!='\n'; ++i)
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

void copy(char to[], char from[])
{
    for (int i =0; (to[i] = from[i]) != '\0'; ++i);
}

