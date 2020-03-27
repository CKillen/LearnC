#include<stdio.h>

#define BIT_LENGTH 8
int rightrot(unsigned x, int n);

int main() {
    printf("\nRight Rot: %d\n", rightrot(25, 3));
    printf("\nExpected Answer to be 35\n");

    printf("\nRight Rot: %d\n", rightrot(89, 4));
    printf("\nExpected Answer to be 149\n");
}

int rightrot(unsigned x, int n) {
    unsigned mask = (1 << n) - 1;
    unsigned lastN = (x & mask) << (BIT_LENGTH - n);
    unsigned shiftedX = x >> n;
    return (lastN | shiftedX);
}
