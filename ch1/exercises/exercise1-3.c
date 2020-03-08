#include<stdio.h>

main()
{
    float farh, celsius;
    float lower, upper, step;

    lower = 0.0;
    upper = 300.0;
    step = 20.0;

    printf("\t F to C Table\n");
    while(farh <= upper) {
        celsius = (5.0 / 9.0) * (farh - 32.0);
        printf("F: %3.0f \t C: %6.2f\n", farh, celsius);
        farh = farh + step;
    }
}
