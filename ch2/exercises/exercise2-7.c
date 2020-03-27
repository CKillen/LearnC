#include <stdio.h>

int invert(int x, int p, int n);

int main() {
    printf("\n%d\n", invert(164, 3, 3));
}

int invert(int x, int p, int n) {
    int mask =  ((1 << n) - 1) << p;
    return x ^ mask;
}
