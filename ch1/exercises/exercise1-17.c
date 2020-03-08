#include<stdio.h>
#define MAXLINE 1000
#define LIMIT 80

int ngetLine(char s[], int limit);

int main() {
    int len = 0;
    char line[MAXLINE];

    while((len = ngetLine(line, MAXLINE)) > 0) {
        if(len >= LIMIT)
            printf("\nLength: %d \nString: %s", len, line);
    }
}

int ngetLine(char s[], int limit) {
    int i, c;
    for(i = 0; i < MAXLINE - 1 && (c = getchar()) != EOF && c != '\n'; ++i)
        s[i] = c;

    if(c == '\n') {
        s[i] = '\n';
        ++i;
    }

     s[i] = '\0';
     return i;

}
