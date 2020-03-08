#include <stdio.h>

#define MAXLINE 1000
#define TABSTOP 4

int ngetline(char line[]);

int main() {
    char line[MAXLINE];
    int length;

    length = 0;
    while((length < ngetline(line)) > 0)
        printf("%s", line);
}

int ngetline(char line[]) {
    int i, j, c;

    for(i = 0; i < MAXLINE && (c = getchar()) != EOF && c != '\n'; ++i) {
        int isTab;

        isTab = 0;
        if(i >= TABSTOP - 1 && c == ' ') {
            for(j = i; j > i - TABSTOP; j--) {
                if(line[j] != ' ')
                    isTab = 0;
                else
                    isTab = 1;

            }
            if(isTab) {
                i = i - TABSTOP + 1;
                line[i] = '\t';
            } else {
                line[i] = c;
            }
        } else {
            line[i] = c;
        }

    }

    if(c == '\n') {
        line[i] = '\n';
        ++i;
    }

    line[i] = '\0';
    return i;
}
