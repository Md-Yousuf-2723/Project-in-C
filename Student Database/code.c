#include<stdio.h>
#define NAME_Char 20

typedef struct stu{
    int roll;
    char name[NAME_Char];
    float marks;
}stu;

void input_student_details(stu student[], int *size);
void check(stu student[], int size, stu *student2);

int main(){
    int MAX = 1;
    printf("How many students data do you want to keep?\n= ");
    scanf("%d",&MAX);

    stu student[MAX];
    input_student_details(student, &MAX);
    
    printf("\nAll student details are successfully saved {^_^}\n");
    
    stu student2;
    printf("\nEnter roll number for search: ");
    scanf("%d",&student2.roll);

    check(student, MAX, &student2);

    return 0;
}
void input_student_details(stu student[], int *size){
    for(int i = 0; i < *size; i++){
        printf("Enter roll number of student - %d : ",i + 1);
        scanf("%d", &student[i].roll);
        getchar();

        printf("Enter name of student - %d : ",i + 1);
        fgets(student[i].name, sizeof(student[i].name), stdin);

        printf("Enter student - %d marks: ", i + 1);
        scanf("%f", &student[i].marks);
        getchar();
        printf("\n");
    }
    return;
}
void check(stu student[], int size, stu *student2){
    for(int i = 0; i < size; i++){
        if(student[i].roll == student2->roll){
            printf("Name: %s",student[i].name);
            printf("Roll: %d",student[i].roll);
            printf("\nMarks: %.2f",student[i].marks);
            return;
        }
    }
    printf("This %d roll number is not found in the database",student2->roll);
    return;
}
