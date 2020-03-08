#include <stdio.h>

#define TABSTOP 3
#define MAXLINE 1000

int ngetline(char line[]);
int main() {
    char line[MAXLINE];
    int length;
    while((length = ngetline(line)) > 0)
        printf("%s", line);
}

int ngetline(char line[]) {
    int i, c, j;

    for(i = 0; i < MAXLINE && (c = getchar()) != EOF && c != '\n'; ++i) {
        if(c == '\t' && i < (MAXLINE - TABSTOP)) {
            for(j = 0; j < TABSTOP; j++) {
                line[i] = ' ';
                ++i;
            }
            i = i - 1;
        } else
            line[i] = c;
    }

    if(c == '\n') {
        line[i] = c;
        ++i;
    }

    line[i] = '\0';
    return i;
}
