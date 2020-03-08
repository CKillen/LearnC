#include<stdio.h>

main()
{
    int fahr;

    for(fahr = 300; fahr >= 0; fahr = fahr -20) {
        printf("F: %3d   c: %6.1f\n", fahr, (5.0 / 9.0) * (fahr - 32.0));
    }
}
