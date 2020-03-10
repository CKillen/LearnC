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
    int iterator, currentQuoteStart, longCommentStart, lineCommentStart;
    int differenceAfterShift;
    iterator = differenceAfterShift = 0;
    currentQuoteStart = lineCommentStart = longCommentStart = -1;
    for(iterator = 0; iterator < length - 1; ++iterator) {
        if(currentQuoteStart < 0
         && line[iterator] == '"')
            currentQuoteStart = iterator;

        if(currentQuoteStart > 0 && line[iterator] == '"')
            currentQuoteStart = -1;

        if(longCommentStart < 0
         && lineCommentStart < 0
         && line[iterator] == '/'
         && line[iterator + 1] == '*'
         && currentQuoteStart < 0)
            longCommentStart = iterator;

        if(longCommentStart >= 0
         && line[iterator - 1] == '*'
         && line[iterator] == '/') {
            differenceAfterShift = shiftArray(line, longCommentStart, iterator, length);
            length = length - differenceAfterShift;
            iterator = iterator - differenceAfterShift - 1;
            longCommentStart = -1;
        }

        if(lineCommentStart < 0
         && line[iterator] == '/'
         && line[iterator + 1] == '/')
            lineCommentStart = iterator;
//        printf("\nlineCommentStart: %d - letter: %c", lineCommentStart, line[iterator]);
        if(lineCommentStart >= 0
         && line[iterator] == '\n') {
            differenceAfterShift = shiftArray(line, lineCommentStart, iterator, length);
            length = length - differenceAfterShift;
            iterator = iterator - differenceAfterShift - 1;
            lineCommentStart = -1;
        }
  //      printf("\nPos: %d - QuoteS: %d - comment: %d\n", iterator, currentQuoteStart, longCommentStart);
    }
}

int shiftArray(char line[], int start, int end, int length) {
    int iterator, difference, newLength;
    iterator = newLength = 0;
    difference = end - start;
 //   printf("Difference:%d - Start:%d - End:%d", difference, start, end);
    for(iterator = start; iterator < length; ++iterator) {
        if((iterator + difference + 1) < length) {
            line[iterator] = line[iterator + difference + 1];
        } else {
            line[iterator] = '\0';
        }
    }
    newLength = length - difference;

    return difference;
}

