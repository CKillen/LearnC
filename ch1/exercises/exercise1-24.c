#include <stdio.h>
#define MAXLINE 1000

int getText(char line[], int limit);
int checkCurlys(char sanatizedLine[], int length);
int checkParenthesis(char sanatizedLine[], int length);
int checkBraces(char sanatizedLine[], int length);
int checkDoubles(char sanatizedLine[], int length);
int checkDoubles(char sanatizedLine[], int length);
void sanatizedArray(char line[], int length);
int main() {
    int length, curlys, parenthesis, braces, doubles, singles;
    char line[MAXLINE];

    length = curlys = parenthesis = braces = doubles = singles = 0;
    while((length = getText(line, MAXLINE)) > 0) {
        printf("\nProblems Detected
                \n{} not closed: %d
                \n() not closed: %d
                \n[] not closed: %d
                \n"" not closed: %d
                \n'' not closed: %d",
                curlys, parenthesis, braces, doubles, singles);
    }
}
