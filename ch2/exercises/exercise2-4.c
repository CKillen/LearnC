#include<stdio.h>

void squeeze(char s[], char r[]);

int main() {
    char string[10] = "Helto";
    char replace[10] = "Hl";
    squeeze(string, replace);;
    printf("%s\n", string);
}

void squeeze(char s[], char r[]) {
    int i, j, k;
        for(k = 0; r[k] != '\0'; k++) {
            for(i = j = 0; s[i] != '\0'; i++)
                if(s[i] != r[k])
                    s[j++] = s[i];

            s[j] = '\0';
        }
}
