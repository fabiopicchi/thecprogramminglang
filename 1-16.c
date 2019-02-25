#undef _POSIX_C_SOURCE
#define _POSIX_C_SOURCE 200112L
#include <stdio.h>
#define MAXLINE 1000

int getline(char  line[], int maxline);
void copy(char to[], char from[]);

int main()
{
    int len;
    int max;
    char line[MAXLINE];
    char longest[MAXLINE];

    max = 0;
    while ((len = getline(line, MAXLINE)) > 0)
        if (len > max) {
            max = len;
            copy(longest, line);
        }
    if (max > 0)
        printf("%d characters\n%s", max, longest);
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

