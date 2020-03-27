#include <stdio.h>

int bitcount(unsigned x);

int main() {
    printf("\n%d\n", bitcount(83));
}

int bitcount(unsigned x) {
    int b;

    for (b = 0; x != 0; x &= (x - 1))
            b++;
    return b;
}
