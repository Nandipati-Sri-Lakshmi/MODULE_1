#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Student {
    int rollno;
    char name[20];
    float marks;
};

void parseInputString(const char* input, struct Student* students, int size) {
    const char* delimiter = " ";
    char* token;

    for (int i = 0; i < size; i++) {
        token = strtok(i == 0 ? strdup(input) : NULL, delimiter);
        if (token == NULL) {
            printf("Error: Insufficient input data\n");
            return;
        }
        students[i].rollno = atoi(token);

        token = strtok(NULL, delimiter);
        if (token == NULL) {
            printf("Error: Insufficient input data\n");
            return;
        }
        strncpy(students[i].name, token, sizeof(students[i].name) - 1);
        students[i].name[sizeof(students[i].name) - 1] = '\0';

        token = strtok(NULL, delimiter);
        if (token == NULL) {
            printf("Error: Insufficient input data\n");
            return;
        }
        students[i].marks = atof(token);
    }
}

int main() {
    int size;
    printf("Enter the number of students: ");
    scanf("%d", &size);
    getchar(); // Clear the newline character from the input buffer

    struct Student* students = (struct Student*)malloc(size * sizeof(struct Student));

    printf("Enter the input string: ");
    char input[100];
    fgets(input, sizeof(input), stdin);
    input[strcspn(input, "\n")] = '\0'; // Remove the newline character from the input string

    parseInputString(input, students, size);

    printf("Student details:\n");
    for (int i = 0; i < size; i++) {
        printf("Roll No: %d, Name: %s, Marks: %.2f\n", students[i].rollno, students[i].name, students[i].marks);
    }

    free(students);
    return 0;
}
