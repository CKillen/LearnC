#include<stdio.h>
#define MAXLIMIT 1000

int ngetLine(char line[], int limit);
void flip(char line[], int length);

int main() {
    int length, i;
    char line[MAXLIMIT];
    while((length = ngetLine(line, MAXLIMIT)) > 0) {
        flip(line, length);
        printf("\n%s\n", line);
        for(i = 0; i < MAXLIMIT; ++i) {
            line[i] = '\0';
        }
    }
}

int ngetLine(char line[], int limit) {
    int i, c;
    for(i = 0; i < limit && (c = getchar()) != EOF && c != '\n'; ++i)
        line[i] = c;

    if(c == '\n') {
        line[i] = c;
        ++i;
    }

    line[i] = '\0';
    return i;
}

void flip(char line[], int length) {
    int i, j;
    char hold;
    j = 0;
    for(i = length - 2; i > j; --i) {
        hold = line[j];
        line[j] = line[i];
        line[i] = hold;
        ++j;
    }
}
