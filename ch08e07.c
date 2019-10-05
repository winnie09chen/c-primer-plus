#include <stdio.h>

void calc_salary(float hours, float salary_hourly);

int main(void)
{
    float hour, salary; 
    char salary_level;
    printf("Input hours:\n");
    scanf("%f", &hour);
    getchar();
    printf("Input salary level:\n");
    printf("a) $8.75/hr\n");
    printf("b) $9.33/hr\n");
    printf("c) $10.00/hr\n");
    printf("d) $11.20/hr\n");
    printf("q) quit\n");
    scanf("%c", &salary_level);
    switch (salary_level)
    {
        case 'a': salary = 8.75;
                    break;
        case 'b': salary = 9.33;
                    break;
        case 'c': salary = 10.00;
                    break;
        case 'd': salary = 11.20;
                    break;
        default: break;
    }
    printf("%.2f hours, $ %.2f/hr\n", hour, salary);
    calc_salary(hour, salary);
    getchar();
    getchar();
    return 0;
} 

void calc_salary(float hours, float salary_hourly)
{
    float s;
    if(hours > 40)
    {
        hours = 40 + (hours - 40)*1.5;
    }
    s = hours * salary_hourly;
    if(s <= 300)
    {
        s = s - s * 0.15;
    }
    else if(s <= 450)
    {
        s = s - 300*0.15 - (s - 300)*0.20;
    }
    else
    {
        s = s - 300*0.15 - 150*0.20 - (s - 300 - 150)*0.25;
    }
    printf("Your salary is %.2f\n", s);
}
