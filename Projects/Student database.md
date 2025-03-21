# Video Link:
https://drive.google.com/file/d/1cmNt85QsAxskrzp_u5o9S2Ql-8THaXSC/view?usp=sharing

----------

# Code
```C
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define NAME_CHAR 20

typedef struct {
    int roll;
    char name[NAME_CHAR];
    float marks;
} Student;

void input_student_details(Student *students, int size);
void check(Student *students, int size, int roll);

int main() {
    int size;
    printf("How many students' data do you want to keep?\n= ");
    scanf("%d", &size);

    Student *students = (Student *)malloc(size * sizeof(Student));
    if (!students) {
        printf("Memory allocation failed\n");
        return 1;
    }

    input_student_details(students, size);
    printf("\nAll student details are successfully saved {^_^}\n");

    int roll;
    printf("\nEnter roll number for search: ");
    scanf("%d", &roll);
    check(students, size, roll);
    
    free(students);
    return 0;
}

void input_student_details(Student *students, int size) {
    for (int i = 0; i < size; i++) {
        printf("Enter roll number of student - %d: ", i + 1);
        scanf("%d", &students[i].roll);
        getchar();

        printf("Enter name of student - %d: ", i + 1);
        fgets(students[i].name, NAME_CHAR, stdin);
        students[i].name[strcspn(students[i].name, "\n")] = '\0';

        printf("Enter marks of student - %d: ", i + 1);
        scanf("%f", &students[i].marks);
        getchar();
    }
}

void check(Student *students, int size, int roll) {
    for (int i = 0; i < size; i++) {
        if (students[i].roll == roll) {
            printf("Name: %s\nRoll: %d\nMarks: %.2f\n", students[i].name, students[i].roll, students[i].marks);
            return;
        }
    }
    printf("Roll number %d not found in the database\n", roll);
}
```
<p>
This is a simple C project.

In this project, user can give as much as student’s info to database. Then later it will be automatically saved.

Then user can search a student’s detail’s by giving his / her roll number input

The concept of C used to develop this projects are:

- Structure
- Dynamic Memory allocation
- Function
- Pointer
- String
</p>
