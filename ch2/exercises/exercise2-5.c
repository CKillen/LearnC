#include<stdio.h>

int check(char s[], char c[]);

int main() {
    char one[10] = "Helllo";
    char find[19] = "xsxc";
    int pos = 0;
    pos = check(one, find);
    printf("Found in pos : %d\n", pos);
}

int check(char s[], char c[]) {
    int i, k;
    i = k = 0;
    for(i = 0; s[i] != '\0'; i++)
        for(k = 0; c[k] != '\0'; k++)
            if(c[k] == s[i])
                return i;

    return -1;
}

