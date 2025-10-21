#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define SIZE 30
typedef struct Student{
    char name[SIZE];
    int roll_number;
    char admission_date[15];
    int year;
    char course[SIZE];
    int attendance;
}student;

int main()
{
    int op;// op = operation
    printf("\n1-press->Add new student information.\n");
    printf("2-press->Update student details.\n");
    printf("3-press->Show all student information.");
    printf("4-press->Search for a student information by student roll number or name.\n");
    printf("5-press->Delete a record for student details.\n");
    printf("6press->Store data permanently in a file.\n");
    printf("0-press->Exit.\n");
    scanf("%d",&op);

    while(1)
    {
        switch(op)
        {
            case 1:
                Add_new_Student_information();
                break;
            case 2:
                Update_student_information();
                break;
            case 3:
                Show_all_student_information();
                break;
            case 4:
                Search_student();
                break;
            case 5:
                Delete_student_information();
                break;
            case 6:
                Store_data_permanently();
                break;
            case 0:
                Exit(0);
            default:
                printf("Cannot performe any operation in this number.");
        }
    }

    return 0;
}