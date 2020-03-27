#include <stdio.h>
#include <limits.h>
#include <float.h>

int main() {
    printf("\nFrom limits.h");
    printf("\nSigned Types");
    printf("\nChar: %d - %d", SCHAR_MIN, SCHAR_MAX);
    printf("\nShort: %d - %d", SHRT_MIN, SHRT_MAX);
    printf("\nInt: %d - %d", INT_MIN, INT_MAX);
    printf("\nLong: %ld - %ld", LONG_MIN, LONG_MAX);
    printf("\nUnsigned Types");
    printf("\nChar: %d - %d", CHAR_MIN, CHAR_MAX);
    printf("\nShort: %d - %d", 0, USHRT_MAX);
    printf("\nInt: %d - %d", 0, UINT_MAX);
    printf("\nLong: %d - %ld", 0, ULONG_MAX);
    printf("\n");
    printf("\nComputated");
    printf("\nSigned Types");
    return 0;
}
