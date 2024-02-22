#include <stdio.h>
#include <stdbool.h>

#define MAX_TAG_LENGTH 100000

char tag[MAX_TAG_LENGTH];

void printArr(char a[], int n) {
    for (int i = 0; i < n; i++) {
        putchar(a[i]);
    }
}

void readTag() {
    int c, i = 0;
    bool is_comment = false;

    while ((c = getchar()) != EOF) {
        if (c == '<') {
            tag[i] = c;
            i++;
            c = getchar(); // read next character after '<'

            if (c == '!') { // check if it's a comment
                is_comment = true;
            } else {
                tag[i] = c;
                i++;
            }

            while ((c = getchar()) != EOF && c != '>' && !is_comment) {
                tag[i++] = c;
            }

            if (is_comment) {
                while ((c = getchar()) != EOF && c != '>') {
                    // Skip comment content
                }
                is_comment = false;
            } else {
                tag[i++] = '>'; // Complete tag
            }

            tag[i++] = '\n';
        }
    }

    printArr(tag, i);
}

int main(void) {
    readTag();
    return 0;
}
