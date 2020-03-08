#include<stdio.h>

void sumTest(int *total, int a, int b);

int main() {
    int total = 0;

    sumTest(&total, 5, 3);

    printf("%d", total);
}

void sumTest(int *total, int a, int b) {
   *total = a + b;
}


