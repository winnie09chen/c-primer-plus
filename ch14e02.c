#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MONTH 12
#define INPUT_LENGTH 32

char * month_full_names[MONTH] = {"January", "February", "March", "April", "May", "June", "July", "August", "September", "October", "November", "December"};
char * month_simple_names[MONTH] = {"Jan", "Feb", "Mar", "April", "May", "Jun", "Jul", "Aug", "Sep", "Oct", "Nov", "Dec"};
int days_of_months[MONTH] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};


void print_days_of_year_1(void);
void print_days_of_year(void);

union month
{
    char * name;
    char * less_name;
    int number;
};

int main(void)
{
    print_days_of_year();
    return 0;
}

void print_days_of_year_1(void)
{
    int year, day, months;
    int choose;
    int total = 0;
    union month month;

    printf("Which year: ");
    scanf("%d", &year);
    getchar();

    printf("What function do you want to input (1, 2, 3):  ");
    scanf("%d", &choose);
    getchar();

    if((year % 4 == 0 && year % 100 != 0) || (year % 400 == 0))
    {
        days_of_months[1] = 29;
    }

    if(choose == 1)
    {
        month.name = (char *)malloc(INPUT_LENGTH * sizeof(char));
        printf("What name: ");
        scanf("%s", month.name);
        getchar();
        printf("What day: ");
        scanf("%d", &day);
        getchar();

        for(int i = 0; i < MONTH; i++)
        {
            if(strcmp(month.name, month_full_names[i]) == 0)
            {
                months = i;
                break;
            }
        }

        for(int i = 0; i < months; i++)
        {
            total += days_of_months[i];
        }

        printf("%d", total + day);
        free(month.name);
    }
    else if(choose == 2)
    {
        month.less_name = (char *)malloc(INPUT_LENGTH * sizeof(char));
        printf("What name: ");
        scanf("%s", month.less_name);
        getchar();
        printf("What day: ");
        scanf("%d", &day);
        getchar();
        for(int i = 0; i < MONTH; i++)
        {
            if(strcmp(month.less_name, month_simple_names[i]) == 0)
            {
                months = i;
                break;
            }
        }

        for(int i = 0; i < months; i++)
        {
            total += days_of_months[i];
        }
        printf("%d", total + day);
        free(month.less_name);
    }
    else
    {
        printf("Which month: ");
        scanf("%d", &month.number);
        printf("What day: ");
        scanf("%d", &day);
        getchar();
        for(int i = 0; i < month.number - 1; i++)
        {
            total += days_of_months[i];
        }
        printf("%d", total + day);
    }
    getchar();
    getchar();
}

void print_days_of_year()
{
    int year = 0;
    int func = 0;
    char input_buffer[INPUT_LENGTH];
    char **month_names = NULL;
    int month_index = 0;
    int day_index = 0;
    int total_days = 0;

    printf("Which year: ");
    scanf("%d", &year);
    getchar();


    if((year % 4 == 0 && year % 100 != 0) || (year % 400 == 0))
    {
        days_of_months[1] = 29;
    }


    printf("What function do you want to input (1, 2, 3):  ");
    scanf("%d", &func);
    getchar();

    if (func < 3)
    {
        printf("What name of month: ");
        scanf("%s", input_buffer);
        getchar();

        if (func == 1)
        {
            month_names = month_full_names;
        }
        else
        {
            month_names = month_simple_names;
        }

        for(int i = 0; i < MONTH; i++)
        {
            if(strcmp(input_buffer, month_names[i]) == 0)
            {
                month_index = i;
                break;
            }
        }
    }
    else
    {
        printf("Which index of month: ");
        scanf("%d", &month_index);
        getchar();
        month_index--;
    }
    

    printf("What day: ");
    scanf("%d", &day_index);
    getchar();

    for(int i = 0; i < month_index; i++)
    {
        total_days += days_of_months[i];
    }
    printf("%d\n", total_days + day_index);

    getchar();
}