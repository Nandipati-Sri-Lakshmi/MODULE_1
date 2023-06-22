#include <stdio.h>

struct Student {
    int rollno;
    char name[20];
    float marks;
};

void displayStudents(struct Student students[], int numStudents) {
    printf("Student Details:\n");
    for (int i = 0; i < numStudents; i++) {
        printf("Student %d:\n", i + 1);
        printf("Roll No: %d\n", students[i].rollno);
        printf("Name: %s\n", students[i].name);
        printf("Marks: %.2f\n", students[i].marks);
        printf("\n");
    }
}

int main() {
    int numStudents;
    printf("Enter the number of students: ");
    scanf("%d", &numStudents);

    struct Student students[numStudents];

    printf("Enter student details:\n");
    for (int i = 0; i < numStudents; i++) {
        printf("Student %d:\n", i + 1);
        printf("Enter Roll No: ");
        scanf("%d", &students[i].rollno);
        printf("Enter Name: ");
        scanf("%s", students[i].name);
        printf("Enter Marks: ");
        scanf("%f", &students[i].marks);
        printf("\n");
    }

    displayStudents(students, numStudents);

    return 0;
}
