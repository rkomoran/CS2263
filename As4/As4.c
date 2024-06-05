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

int find_first(char *input, int index) {
    for (int i = index; input[i] != '\0'; i++) {
        if (input[i] == '<' && input[i + 1] != '!') {
            return i;
        }
    }
    return -1;
}

int find_end(char *input, int index) {
    for (int i = index; input[i] != '\0'; i++) {
        if (is_end(input[i])) {
            return i;
        }
    }
    return -1;
}

bool is_tag_duplicate(char *input, int start, int end, char **stored_tags) {
    while (*stored_tags != NULL) {
        if (strncmp(input + start, *stored_tags, (end - start + 1)) == 0) {
            return true;
        }
        stored_tags++;
    }
    return false;
}

void add_count(char *input, int start, int end, char **stored_tags, int *counts, int max_tags) {
    for (int i = 0; i < max_tags; i++) {
        if (stored_tags[i] == NULL)
            break;
        
        if (strncmp(input + start, stored_tags[i], (end - start + 1)) == 0) {
            // Increment the count at the corresponding index in counts array
            counts[i] += 1;
            return;
        }
    }
}

char **store_tags(char *input, int size, int *tag_counts, char **start_tags, int max_tags) {
    int index = 0;
    int tag_ptr_index = 0;

    while (index < size && tag_ptr_index < max_tags) {
        int opening_tag = find_first(input, index);
        if (opening_tag == -1) {
            break;
        }

        int closing_tag = find_end(input, opening_tag);
        if (closing_tag == -1) {
            break;
        }

        // Check for duplicates before storing the tag
        if (!is_tag_duplicate(input, opening_tag, closing_tag, start_tags)) {
            start_tags[tag_ptr_index] = (char *)malloc((closing_tag - opening_tag + 2) * sizeof(char)); // Allocate memory for the tag
            if (start_tags[tag_ptr_index] == NULL) {
                // Memory allocation failed, handle error
                fprintf(stderr, "Memory allocation failed\n");
                exit(EXIT_FAILURE);
            }
            strncpy(start_tags[tag_ptr_index], input + opening_tag, (closing_tag - opening_tag + 1)); // Copy the tag
            start_tags[tag_ptr_index][closing_tag - opening_tag + 1] = '\0'; // Null-terminate the string
            // Increment the count for the tag type
            tag_counts[tag_ptr_index] += 1;
            tag_ptr_index++; // Move to the next tag pointer
        } else {
            // If it's a duplicate, increment the count
            add_count(input, opening_tag, closing_tag, start_tags, tag_counts, max_tags);
        }

        index = closing_tag + 1;
    }

    if (tag_ptr_index < max_tags) {
        start_tags[tag_ptr_index] = NULL; // Mark the end of the array with a NULL pointer
    }

    return start_tags;
}

void print_tags(char **stored_tags, int *tag_counts, int max_tags) {
    for (int i = 0; i < max_tags && stored_tags[i] != NULL; i++) {
        char *end_tag = stored_tags[i];
        while (!is_end(*end_tag))
            end_tag++;
        int tag_length = (int)(end_tag - stored_tags[i] - 1);
        char *tag_name = stored_tags[i] + 1; // Skip the opening angle bracket

        // Check if the tag name is not empty
        if (tag_length > 0) {
            // Print tag name
            printf("%.*s", tag_length, tag_name);

            // Print count
            printf(" %d\n", tag_counts[i]);
        }
    }
}

void readFile(char *filename) {
    FILE *file = fopen(filename, "r");
    if (file == NULL) {
        fprintf(stderr, "Error opening file\n");
        exit(EXIT_FAILURE);
    }

    char *input_array = (char *)malloc(sizeof(char) * MAX_CHARACTERS);
    if (input_array == NULL) {
        // Memory allocation failed, handle error
        fprintf(stderr, "Memory allocation failed\n");
        exit(EXIT_FAILURE);
    }

    int c, index = 0;
    while ((c = fgetc(file)) != EOF && index < MAX_CHARACTERS - 1) {
        input_array[index++] = c;
    }
    input_array[index] = '\0';

    fclose(file);

    char **start_tags = (char **)malloc(sizeof(char *) * MAX_TAGS);
    if (start_tags == NULL) {
        // Memory allocation failed, handle error
        fprintf(stderr, "Memory allocation failed\n");
        exit(EXIT_FAILURE);
    }

    int *tag_counts = (int *)malloc(sizeof(int) * MAX_TAGS);
    if (tag_counts == NULL) {
        // Memory allocation failed, handle error
        fprintf(stderr, "Memory allocation failed\n");
        exit(EXIT_FAILURE);
    }

    for (int i = 0; i < MAX_TAGS; i++) {
        start_tags[i] = NULL; // Initialize to NULL
        tag_counts[i] = 0; // Initialize to 0
    }

    char **stored_tags = store_tags(input_array, index, tag_counts, start_tags, MAX_TAGS);

    print_tags(stored_tags, tag_counts, MAX_TAGS);

    // Free allocated memory
    for (int i = 0; stored_tags[i] != NULL; i++) {
        free(stored_tags[i]);
    }
    free(input_array);
    free(start_tags);
    free(tag_counts);
}


int main(int argc, char **argv) {
    if (argc != 2) {
        printf("ERROR: Provide a file to read.\n");
        return EXIT_FAILURE;
    }

    readFile(argv[1]);
    return EXIT_SUCCESS;
}