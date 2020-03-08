#include<stdio.h>

double tempConverter(int fahr);

int main() {
    int fahr;
    double celcius;
    int lower, upper, step;

    lower = 0;
    step = 20;
    upper = 300;

    fahr = celcius = 0;
    while(fahr <= upper) {
        printf("\nF:%3d   C:%6.2f", fahr, tempConverter(fahr));
        fahr = fahr + step;
    }
    printf("\n");
}

double tempConverter(int fahr) {
    return (5.0 / 9.0) * (fahr - 32.0);
}
