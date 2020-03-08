#include<stdio.h>

#define LOWER 0
#define UPPER 300
#define STEP 20

main()
{
    int fahr;

    for(fahr = 0; fahr <= UPPER; fahr = fahr + STEP) {
        printf("F: %3d   C: %6.2f \n", fahr, (5.0 / 9.0) * (fahr - 32.0));
        fahr = fahr + STEP;
    }
}
