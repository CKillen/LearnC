#include<stdio.h>

#define OUT 0
#define IN 1
main() {
    int c, nl, nw, nc, state;

    state = OUT;
    nw = nc = 0;
    nl = 1;
    while((c = getchar()) != EOF) {
        ++nc;
        if(c == '\n') {
            ++nl;
        }
        if(c == ' ' || c == '\n' || c == '\t'){
            state = OUT;
        }
        else if (state == OUT) {
            state = IN;
            ++nw;
        }
    }
    printf("\nLines:%d Words:%d Chars:%d\n", nl, nw, nc);
}
