#include <stdio.h>
#define MAXLINE 1000

int getline(char  line[], int maxline);
void copy(char to[], char from[]);

int main()
{
    int len;
    int i;
    char line[MAXLINE];

    while ((len = getline(line, MAXLINE)) > 0)
        if (len > 1) {
            if (len >= MAXLINE)
                len = MAXLINE - 1;
            for (i = len - 1; i>=0 && (line[i]=='\n' || line[i]==' ' || line[i]=='\t'); --i)
                ;
            if (line[len-1] == '\n') {
                line[i+1] = '\n';
                ++i;
            }
            line[i+1] = '\0';
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

