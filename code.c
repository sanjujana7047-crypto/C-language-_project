#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define MAX_STUDENT 100
#define FILE_NAME "Student.txt"

typedef struct Student{
    int roll;
    char name[50];
    char course[50];
    float marks;
    char academic_record[50];
    int attendance;
}student;

void Add_new_student_information(student students[],int *count);
void Update_student_information(student students[],int count);
void Show_all_student_information(student students[],int count);
void Search_student(student students[],int count);
int Delete_student_information(student students[],int *count);
int Sort_by_rollno(student students[],int count);
int Upto_date_attendance(student students[],int count);
void Save_to_file(student students[],int count);
void Load_from_file(student students[],int *count);

int main()
{
    student students[MAX_STUDENT];
    student deletestudents[MAX_STUDENT];
    int op;// op = operation
    int count = 0;

    Load_from_file(students,&count);

    while(1)
    {
        printf("\n===== Student Information System =====\n");
        printf("\n1-press->Add new student information.\n");
        printf("2-press->Update student details.\n");
        printf("3-press->Show all student information.\n");
        printf("4-press->Search for a student information by student roll number or name.\n");
        printf("5-press->Delete student details.\n");
        printf("6-press->sort by roll number and save.\n");
        printf("7-press->add attendance for upto date.\n");
        printf("0-press->Store data permanently in a file and exit.\n");
        printf("Enter your choice :");
        scanf("%d",&op);

        switch(op)
        {
            case 1:
                Add_new_student_information(students,&count);
                break;
            case 2:
                Update_student_information(students,count);
                break;
            case 3:
                Show_all_student_information(students,count);
                break;
            case 4:
                Search_student(students,count);
                break;
            case 5:
                Delete_student_information(students,&count);
                break;
            case 6:
                Sort_by_rollno(students,count);
                break;
            case 7:
                Upto_date_attendance(students,count);
                break;
            case 0:
                Save_to_file(students,count);
                exit(0);
            default:
                printf("Cannot perform any operation in this number.");
        }
    }

    return 0;
}

void Add_new_student_information(student students[],int *count)
{
    student  s;    
    if(*count >= MAX_STUDENT)
    {
        printf("Can't store another student information because storage is full.");
        return;
    }
    printf("\n-----Enter student details-----\n");
    printf("Enter roll number :");
    scanf("%d",&s.roll);
    getchar();
    printf("Student name :");
    fgets(s.name, sizeof(s.name), stdin);
    s.name[strcspn(s.name, "\n")] = '\0';
    printf("Course name :");
    fgets(s.course, sizeof(s.course), stdin);
    s.course[strcspn(s.course, "\n")] = '\0';
    printf("Marks :");
    scanf("%f",&s.marks);
    getchar();
    printf("Academic record :");
    fgets(s.academic_record, sizeof(s.academic_record), stdin);
    s.academic_record[strcspn(s.academic_record, "\n")] = '\0';
    printf("Total attendance :");
    scanf("%d",&s.attendance);
    for(int i=0;i<*count;i++)
    {
        if(s.roll == students[i].roll)
        {
            printf("This roll number student already exits so, do not store this student informatiom.\n");
            return;
        }
    }
    students[*count] = s;
    (*count)++;
    printf("Student added successfully.\n");
    Save_to_file(students,*count);
}

void Update_student_information(student students[],int count)
{   
    student s; 
    int roll;
    printf("Enter student roll number :");
    scanf("%d",&roll);
    for(int i=0; i < count;i++)
    {
        if(students[i].roll == roll)
        {
            printf("----student update information----\n");
            getchar();
            printf("Enter student name :");
            fgets(students[i].name, sizeof(students[i].name), stdin);
            students[i].name[strcspn(students[i].name, "\n")] = '\0';
            printf("Course name:");
            fgets(students[i].course, sizeof(students[i].course), stdin);
            students[i].course[strcspn(students[i].course, "\n")] = '\0';
            printf("Marks :");
            scanf("%f,\n",&students[i].marks);
            getchar();
            printf("Academic record :");
            fgets(students[i].academic_record, sizeof(students[i].academic_record), stdin);
            students[i].academic_record[strcspn(students[i].academic_record, "\n")] = '\0';
            printf("Attendance :");
            scanf("%d,\n",&students[i].attendance);
            printf("If you are change student roll number (put new roll or  not change then put old roll) :");
            scanf("%d",&students[i].roll);
            Save_to_file(students,count);
            return;
        }
    }
    printf("This student data not found !");
}

void Show_all_student_information(student students[],int count)
{
    printf("=====Added students information=====\n");
    printf("\n%-8s | %-20s | %-30s | %-8s | %-18s | %-12s\n",
       "Roll", "Name", "Course", "Marks", "Academic Record", "Attendance");
    printf("-------------------------------------------------------------------------------------------------------------\n");
    if(count == 0)
    {
        printf("No records found.\n");
        return;
    }
    for(int i=0;i<count;i++)
    {
        printf("%-8d |%-20s  |%-30s  | %-8.2f |%-18s  | %-12d\n",students[i].roll,
        students[i].name,students[i].course,students[i].marks,
        students[i].academic_record,students[i].attendance);
    }
}

void Search_student(student students[],int count)
{
    int n,roll;
    char stu[50];
    int found = 0;
    printf("1->search by roll number and 2->search by name :");
    scanf("%d",&n);
    if(n == 1)
    {
        printf("Enter roll number :");
        scanf("%d",&roll);
    }
    else if(n == 2)
    {
        printf("Enter student name :");
        scanf(" %[^\n]", stu);
    }
    else
    {
        printf("not perform search on this botton !\n");
        return;
    }
    printf("\n---student details---\n");
    for(int i=0;i<count;i++)
    {
        if(students[i].roll == roll)
        {
            printf("Name :%s\nRoll number :%d\nCourse name :%s\nMarks :%2f\nAcademic record :%s\nAttendance :%d\n",
                students[i].name,students[i].roll,students[i].course,students[i].marks,students[i].academic_record,students[i].attendance);
            found = 1;
            break;
        }
        if(strcmp(students[i].name, stu) == 0)
        {
            printf("Name :%s\nRoll number :%d\nCourse name :%s\nMarks :%f\nAcademic record :%s\nAttendance :%d\n",
                students[i].name,students[i].roll,students[i].course,students[i].marks,students[i].academic_record,students[i].attendance);
            found = 1;
            break;
        }
    }
    if(found == 0)
        printf("Not found data !");
}

int Delete_student_information(student students[],int *count)
{
    int roll;
    student temp;
    printf("Enter roll number :");
    scanf("%d",&roll);
    int found  = 0;
    for (int i = 0; i < *count; i++)
    {
        if (students[i].roll == roll) 
        {
            found = 1;
            for (int j = i; j < *count - 1; j++) 
            {
                students[j] = students[j + 1];
            }
            (*count)--;
            printf("Student record deleted successfully!\n");
            Save_to_file(students, *count);
            break;
        }
    }
    if(found == 0)
    {
        printf("Roll number %d not found data error !\n",roll);
        return 0;
    }
    return 1;
}

int Sort_by_rollno(student students[],int count)
{
    student temp;
    for(int i=0;i<count-1;i++)
    {
        for(int j=i+1;j<count;j++)
        {
            if(students[i].roll > students[j].roll)
            {
                temp = students[i];
                students[i] = students[j];
                students[j] = temp;                
            }
        }
    }
    printf("Now if check student information sort by roll number then press 3->show  all student information.\n");
    Save_to_file(students,count);
    return 1;
}

int Upto_date_attendance(student students[],int count)
{
    int n = 0;
    if(count == 0)
    {
        printf("Not store data.\n");
        return 0;
    }
    printf("----Start attendance----\n");
    printf("If present press->(how many credit point you give ?) and absent press->0.\n");
    for(int i=0;i<count;i++)
    {
        printf("Roll number %d :",students[i].roll);
        scanf("%d",&n);
        students[i].attendance = (students[i].attendance + n);
    }
    Save_to_file(students,count);
    printf("Attendance successfull.\n");
    return 1;
}

void Save_to_file(student students[],int count)
{
    FILE *fp = fopen(FILE_NAME,"w");
    if(fp == NULL)
    {
        printf("file not open error !\n");
        return;
    }
    for(int i = 0;i < count;i++)
    {
        fprintf(fp , "%d,%s,%s, %2f,%s, %d\n",students[i].roll,
        students[i].name,students[i].course,students[i].marks,
        students[i].academic_record,students[i].attendance);
    }
    fclose(fp);
}

void Load_from_file(student students[], int *count) {
    FILE *fp = fopen(FILE_NAME, "r");
    if (fp == NULL)
        return; // file might not exist yet
    while (fscanf(fp, "%d,%49[^,],%49[^,],%f,%49[^,],%d\n",
                &students[*count].roll,
                students[*count].name,
                students[*count].course,
                &students[*count].marks,
                students[*count].academic_record,
                &students[*count].attendance) == 6)
    {
    (*count)++;
    }
    fclose(fp);
}
