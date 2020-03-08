#include<stdio.h>

main() {
    int c, nl, nt, b;

    nl = 0;
    nt = 0;
    b = 0;
    while((c = getchar()) != EOF) {
        if(c == '\n') {
            ++nl;
        }
        if(c == '\t') {
            ++nt;
        }
        if(c == ' ') {
            ++b;
        }

    }
    printf("\nLines: %d \nTabs: %d \nBlanks: %d \n", nl, nt, b);
}

