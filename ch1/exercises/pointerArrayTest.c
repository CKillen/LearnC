#include<stdio.h>

void tested(int test[]);

int main() {
    int test[3] = {5, 6, 7};
    int i;
    tested(test);
    for(i = 0; i < 3; ++i)
        printf("\n%d\n", test[i]);

}


void tested(int test[]) {
    test[0] = 24;
}
