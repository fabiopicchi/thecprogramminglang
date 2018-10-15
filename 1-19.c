#include <stdio.h>
#define MAXLINE 1000

int getline(char  line[], int maxline);
void copy(char to[], char from[]);
void reverse(char from[]);

int main()
{
    int len;
    char line[MAXLINE];

    while ((len = getline(line, MAXLINE)) > 0) {
        reverse(line);
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
    for (int i = 0; (to[i] = from[i]) != '\0'; ++i);
}

void reverse(char from[])
{
    int len;

    for (len = 0; from[len] != '\0'; ++len);

    for (int i = 0; i < len/2; ++i) {
        char c = from[i];
        from[i] = from[len-1 - i];
        from[len-1 - i] = c;
    }
}
