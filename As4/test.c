#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <ctype.h>
#include <string.h>

#define MAX_CHARACTERS 100000
#define MAX_TAGS 100

bool is_end(char in) {
    return (isspace(in) || in == '/' || in == '>' || in == ' ');
}

int find_first(char *input, int start_index, int max_index) {
    int index = start_index;
    while (index < max_index && input[index] && input[index] != '<') {
        index++;
    }
    return index;
}

int find_end(char *input, int start_index, int max_index) {
    int index = start_index;
    while (index < max_index && input[index] && input[index] != '>') {
        index++;
    }
    return index;
}


void readFile(char *filename) {
    FILE *file = fopen(filename, "r");
    char *input_array;
    input_array = malloc(sizeof(char) * MAX_CHARACTERS);
    int c, index = 0;

    while ((c = fgetc(file)) != EOF && index < MAX_CHARACTERS - 1) {
        input_array[index++] = c;
    }
    input_array[index] = '\0';

    fclose(file);

    // Start parsing HTML tags
    int ptr = 0;
    char tags[MAX_TAGS][MAX_CHARACTERS]; // Array to store tags
    int counts[MAX_TAGS] = {0}; // Array to store tag counts
    int tag_index = 0;

    while (ptr < index && input_array[ptr]) {
    int start = find_first(input_array, ptr, index);
    if (input_array[start] == '<') {
        int end = find_end(input_array, start, index);
        if (input_array[end] == '>') {
            // Found a complete tag
            int length = end - start + 1;
            if (tag_index < MAX_TAGS) {
                strncpy(tags[tag_index], input_array + start, length);
                tags[tag_index][length] = '\0';
                counts[tag_index]++;
                tag_index++;
            } else {
                printf("Max tags exceeded. Exiting.\n");
                break;
            }
        }
        ptr = end + 1;
    } else {
        ptr++;
    }
}

    // Print tag occurrences
    for (int i = 0; i < tag_index; i++) {
        printf("%s %d\n", tags[i], counts[i]);
    }

    free(input_array);
}

int main(int argc, char **argv) {
    if (argc != 2) {
        printf("ERROR: Provide a file to read.\n");
        return EXIT_FAILURE;
    }

    readFile(argv[1]);
    return 0;
}
