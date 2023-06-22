#include <stdio.h>
#include <stdlib.h>

struct Student {
    int rollno;
    char name[20];
    float marks;
};

void initializeStudents(struct Student *students, int size) {
    int i;
    for (i = 0; i < size; i++) {
        printf("Enter details for student %d:\n", i + 1);
        printf("Roll No: ");
        scanf("%d", &students[i].rollno);
        printf("Name: ");
        scanf("%s", students[i].name);
        printf("Marks: ");
        scanf("%f", &students[i].marks);
    }
}

void displayStudents(struct Student *students, int size) {
    int i;
    printf("Student Details:\n");
    for (i = 0; i < size; i++) {
        printf("Roll No: %d, Name: %s, Marks: %.2f\n", students[i].rollno, students[i].name, students[i].marks);
    }
}

void sortStudents(struct Student *students, int size) {
    int i, j;
    struct Student temp;
    
    for (i = 0; i < size - 1; i++) {
        for (j = 0; j < size - i - 1; j++) {
            if (students[j].marks < students[j + 1].marks) {
                
                temp = students[j];
                students[j] = students[j + 1];
                students[j + 1] = temp;
            }
        }
    }
}

int main() {
    int numStudents;
    struct Student *students;
    
    printf("Enter the number of students: ");
    scanf("%d", &numStudents);
    
    students = (struct Student*) malloc(numStudents * sizeof(struct Student));
    
    initializeStudents(students, numStudents);
    
    printf("\nBefore Sorting:\n");
    displayStudents(students, numStudents);
    
    sortStudents(students, numStudents);
    
    printf("\nAfter Sorting:\n");
    displayStudents(students, numStudents);
    
    free(students);
    
    return 0;
}
