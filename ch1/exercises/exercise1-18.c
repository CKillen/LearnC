#include<stdio.h>
#define MAXLIMIT 1000

int ngetLine(char line[], int limit);
int removeTrails(char line[], int length);
int main() {
    int length, i;
    char line[MAXLIMIT];

    while((length = ngetLine(line, MAXLIMIT)) != 0) {
        if(length != 1 && line[0] != '\n' && line[0] != ' ' && line[0] != '\t') {
            printf("Length: %d", removeTrails(line, length));
            printf("\nRemoved Trailing Blanks & Tabs: %s\n", line);
            for(i = 0; i < length; ++i)
                line[i] = '\0';
        }
    }
}

int ngetLine(char line[], int limit) {
    int i, c;
    for(i = 0; i < limit - 1 && (c = getchar()) != EOF && c != '\n'; ++i)
        line[i] = c;

    if(c == '\n') {
       line[i] = ' ';
       ++i;
    }

    line[i] = ' ';
    return i;
}

int removeTrails(char line[], int length) {
    int i;
    for(i = length;
            i > 0 && (line[i] == ' ' || line[i] == '\t' || line[i] == '\0');
            --i) {
        line[i] = '\0';
    }

    ++i;
    line[i] = '\n';
    return i;
}
