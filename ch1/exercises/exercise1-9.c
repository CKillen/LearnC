#include<stdio.h>

main() {
    int c, previousc;
    previousc = -1;
    while((c = getchar()) != EOF) {
        if(c != ' ' || previousc != ' ') {
            putchar(c);
        }
        previousc = c;
    }
 }
