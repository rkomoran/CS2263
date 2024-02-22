#include <stdio.h>
#include <stdbool.h>
#include <string.h>
int main() {
    int c;
    bool inTag = false;
    bool in_comment = false;
    
    while ((c = getchar()) != EOF) {
        // Inside tag
        if (c == '<') {
            if (!in_comment)
            {
                inTag = true;
            }
        }
        // Have to check if next character after '<' is '!'
        else if (c == '!') {
            if (inTag) {
                in_comment = true;
            }
        }
        // Outside tag
        else if (c == '>') {
            if (!in_comment) {
                putchar('>');
                putchar('\n');
            }
            inTag = false;
            in_comment = false;
        }
        // Output only if not in comment and in tag
        if (inTag && !in_comment) {
            putchar(c);
        }
    }
    return 0;
}
