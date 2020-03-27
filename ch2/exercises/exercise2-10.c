#include <stdio.h>

char lower(char letter);

int main() {
    char test = 'H';
    char test2 = 'j';

    printf("\nOutput: %c %c\nExpected: h j\n\n", lower(test), lower(test2));
}

char lower(char letter) {
    return (letter >= 65 && letter <= 90) ? letter + 32 : letter;
}
