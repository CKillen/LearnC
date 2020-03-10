#include <stdio.h>
#define MAXLINE 1000

int getText(char line[], int limit);
void sanatize(char line[], int length);
int shiftArray(char line[], int start, int end, int length);

int main() {
    int length;
    char line[MAXLINE];

    length = 0;
    while((length = getText(line, MAXLINE)) > 0) {
        sanatize(line, length);
        printf("\n%s\n", line);
    }
}

int getText(char line[], int limit) {
    int iterator, character;

    iterator = character = 0;
    for(iterator = 0;
        (character = getchar()) != EOF && iterator < limit - 1;
        ++iterator) {
            line[iterator] = character;
        }

    if(character ==EOF) {
        line[iterator] = '\0';
    }
    return iterator;
}

void sanatize(char line[], int length) {
    //Want to find either // or /* */
    //remove from /* */ to  if that type of comment
    //otherwise remove till \n for //
    //DONT FORGET WHEN // IS IN STRING IT SHOULDN'T TAKE IT OUT
    int iterator, currentQuoteStart, currentCommentStart;
    iterator = 0;
    currentQuoteStart = -1;
    for(iterator = 0; iterator < length - 1; ++iterator) {
        if(currentQuoteStart > 0 && line[iterator] == '"')
            currentQuoteStart = -1;
        printf("\nPos: %d - QuoteS: %d - comment: %d\n", iterator, currentQuoteStart, currentCommentStart);
        if(currentQuoteStart < 0
         && line[iterator] == '"')
            currentQuoteStart = iterator;
        if(currentCommentStart < 0
         && line[iterator] == '/'
         && line[iterator] == '*'
         && currentQuoteStart < 0)
            currentCommentStart = iterator;

        if(currentCommentStart > 0
         && line[iterator] == '*'
         && line[iterator + 1] == '/') {
            shiftArray(line, currentCommentStart, iterator, length);
        }
    }
}

int shiftArray(char line[], int start, int end, int length) {
    int iterator, difference, newLength;
    iterator = newLength = 0;
    difference = end - start;
    for(iterator = start; iterator < end; ++iterator) {
        if((iterator + difference + 1) < length) {
            line[iterator] = line[iterator + difference + 1];
        } else {
            line[iterator] = '\0';
        }
    }
    newLength = length - difference;

    return newLength;
}

