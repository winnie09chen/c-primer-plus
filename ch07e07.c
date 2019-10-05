#include <stdio.h>
void clac_salary(int hours, int salary_hourly);
int main(void)
{
    int hours;
    float salary_hour = 10.00;
    printf("Input your worktime:\n");
    scanf("%d", &hours);
    clac_salary(hours, salary_hour);
    getchar();
    getchar();
    return 0;
}
void clac_salary(int hours, int salary_hourly)
{
    float s, s_1;
    if(hours > 40)
    {
        hours = 40 + (hours - 40) * 1.5;
    }
    s = hours * salary_hourly;
    s_1 = hours * salary_hourly;
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
    printf("net salary: %.2f\n", s);
    printf("salary: %.2f\n", s_1);
}