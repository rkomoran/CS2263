#include <stdio.h>
#include <stdlib.h>

typedef struct student {
    char* lastname;
} Student;

void getNames(Student *students, int num_students) {
    for (int i = 0; i < num_students; i++) {
        students[i].lastname = malloc(sizeof(char) * 1024);
        if (students[i].lastname == NULL) {
            perror("Failed to allocate memory");
            exit(EXIT_FAILURE);
        }
        printf("Enter last name for student %d:\n", i + 1);
        scanf("%s", students[i].lastname); 
    }
}

int main() {
    int num_students;

    printf("Enter the number of students: ");
    scanf("%d", &num_students);

    Student *students = malloc(sizeof(Student) * num_students);
    if (students == NULL) {
        perror("Failed to allocate memory");
        return EXIT_FAILURE;
    }

    getNames(students, num_students);

    for (int i = 0; i < num_students; i++) {
        printf("students[%d].lastName = %s\n", i, students[i].lastname);
    }

    for (int i = 0; i < num_students; i++) {
        free(students[i].lastname);
    }
    free(students);

    return 0;
}
