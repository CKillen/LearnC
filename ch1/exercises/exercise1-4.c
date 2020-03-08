#include<stdio.h>

main()
{
    float celsius, farh;
    float lower, upper, step;

    lower = 0;
    upper = 300;
    step = 20;
    farh = lower;
    while(farh <= upper) {
        celsius = (5.0 / 9.0) * (farh - 32.0);
        printf("C: %6.1f   F: %3.0f\n", celsius, farh);
        farh = farh + step;
    }
}
