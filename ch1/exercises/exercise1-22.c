#include<stdio.h>

#define MAXLINE 1000
#define FOLDPOINT 10

int ngetline(char line[]);

int main() {
    int length;
    char line[MAXLINE];

    length = 0;
    while((length = ngetline(line)) > 0)
        printf("%s", line);
}

int ngetline(char line[]) {
    int i, si, bs, j, c, cl;

    si = c = cl = 0;
    //if no spaces fold at foldpoint
    bs = FOLDPOINT;
    for(i = 0; i < MAXLINE && (c = getchar()) != EOF && c != '\n'; ++i) {
        if(c == ' ' || c == '\t')
            bs = i;
        if(si == FOLDPOINT) {
            printf("bs: %d, i: %d", bs, i);
            //find last space and insert \n reset
            line[bs] = '\n';
            printf("linechange??? : %c\n", line[bs]);
            ++cl;
            bs = cl + FOLDPOINT;
            si = 0;
            if(bs == si)
                ++i;
        }
        line[i] = c;
        ++si;
    }

    if(c == '\n') {
        line[i] = '\n';
        ++i;
    }

    line[i] = '\0';
    return i;
}
