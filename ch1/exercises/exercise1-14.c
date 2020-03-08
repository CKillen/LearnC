#include<stdio.h>

#define ACHAR 97
#define ZCHAR 122
#define LETTERCOUNT 26
#define AUPPERCASE 65
#define ZUPPERCASE 90
main() {
    //A:ACHAR Z:ZCHAR
    int i, j, c;
    int letterCount[LETTERCOUNT];

    for(i = 0; i < LETTERCOUNT; ++i)
        letterCount[i] = 0;

    while((c = getchar()) != EOF)
        if(c >= ACHAR && c <= ZCHAR)
           ++letterCount[c - ACHAR];
        else if(c >= AUPPERCASE && c <= ZUPPERCASE)
           ++letterCount[c - AUPPERCASE];

    printf("\n\n\n");

    for(i = 0; i < LETTERCOUNT; ++i) {
        printf("\n%2c : ", i + ACHAR);
        for(j = 0; j < letterCount[i]; ++j)
            printf("0");
    }
    printf("\n\n\n");
}
