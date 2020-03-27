#include <stdio.h>

int setbits(int x, int p, int n, int y);

int main() {
   printf("\n%d\n", setbits(157, 5, 3, 5));
   printf("\n%d\n", setbits(172, 7, 4, 15));
}

int setbits(int x, int p, int n, int y) {
    int shift = p - n + 1;
    unsigned mask =  (1 << n) - 1;
    return (x & ~(mask << shift) | (y << shift));
}
