#include<stdio.h>
#define MAXLINE 100

int getLine(char line[], int maxline);
void copy(char to[], char from[]);

int main() {
    int len, max;
    char line[MAXLINE], longest[MAXLINE];

    max = 0;
    while ((len = getLine(line, MAXLINE)) > 0)
        if (len > max) {
            max = len;
            copy(longest, line);
        }
    if (max > 0)
        printf("%s", longest);
    return 0;
}

int getLine(char s[], int lim)
{
    int c, i;

    //This will run until EOF, new line or over the limit
    for (i = 0; i < lim - 1 && (c = getchar()) != EOF && c != '\n'; ++i)
        s[i] = c;
    //if exiting the forloop it will wait for this, adding a newline to the end
    //note if the for loop hits max it will == MAXLINE - 1
    //That means the second to last value will get overridden by the below if
    //and the last value will be null
    if( c == '\n') {
        s[i] = c;
        ++i;
    }
    //This will add a null value to the end of the string
    s[i] = '\0';
    //this will return i so that we can see which is the longest
    //we dont need to return array because arrays get overridden automatically
    return i;
}

void copy(char to[], char from[])
{
    int i;

    i = 0;
    //this stores from [i] into to[i] and until it hits the null char at the end
    //of array
    while((to[i] = from[i]) != '\0')
        ++i;
}
