#include <stdio.h>
#include <stdlib.h>

#define STUDENT_SIZE 4
#define GRADE_SIZE 3

struct name
{   
    char * first_name;
    char * last_name;
};

struct student
{
    struct name name;
    float grade[GRADE_SIZE];
    float grade_avg;
};

int main(void)
{
    struct student students[STUDENT_SIZE];
    float total = 0;
    
    for(int i = 0; i < STUDENT_SIZE; i++)
    {
        students[i].name.first_name = "gang";
        students[i].name.last_name = (char *)malloc(20 * sizeof(char));
    }

    for(int i = 0; i < STUDENT_SIZE; i++)
    {
        printf("What's the %d student's grade: ", i + 1);
        scanf("%f %f %f", students[i].grade, students[i].grade+1, students[i].grade+2);
        printf("What's the %d student's last name: ", i + 1);
        scanf("%s", students[i].name.last_name);
        
        total = 0;
        for(int j = 0; j < GRADE_SIZE; j++)
        {
            total += students[i].grade[j];
        }
        students[i].grade_avg = total / 3;
    }

    for(int i = 0; i < STUDENT_SIZE; i++)
    {
        printf("%s %s's grade avg is %.2f.\n", students[i].name.last_name, students[i].name.first_name, students[i].grade_avg);
    }

    total = 0;
    for(int i = 0; i < STUDENT_SIZE; i++)
    {
        total += students[i].grade_avg;
    }
    printf("The grade avg of all class is %.2f.\n", total / STUDENT_SIZE);
    getchar();
    getchar();
    return 0;
}