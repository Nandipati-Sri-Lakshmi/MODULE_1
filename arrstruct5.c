#include <stdio.h>
#include <string.h>

struct Student {
    int rollno;
    char name[20];
    float marks;
};

void searchStudentByName(struct Student students[], int size, char searchName[]) {
    int found = 0;
    printf("Search Results:\n");
    for (int i = 0; i < size; i++) {
        if (strcmp(students[i].name, searchName) == 0) {
            printf("Roll No: %d, Name: %s, Marks: %.2f\n", students[i].rollno, students[i].name, students[i].marks);
            found = 1;
        }
    }
    if (!found) {
        printf("No student with the given name found.\n");
    }
}

int main() {
    int size;
    printf("Enter the number of students: ");
    scanf("%d", &size);

    struct Student students[size];

    for (int i = 0; i < size; i++) {
        printf("Enter details for student %d:\n", i + 1);
        printf("Roll No: ");
        scanf("%d", &students[i].rollno);
        printf("Name: ");
        scanf("%s", students[i].name);
        printf("Marks: ");
        scanf("%f", &students[i].marks);
    }

    char searchName[20];
    printf("Enter the name to search: ");
    scanf("%s", searchName);

    searchStudentByName(students, size, searchName);

    return 0;
}

