#include <stdio.h>
void address(float * a, float * b, float * c);
void number_1(float * temp, float * temp_2, float * temp_3);
void number_2(float * temp, float * temp_2, float * temp_3);
int main(void)
{
    float a = 3.1415, b = 3.1513, c = 2.9999;
    address(&a, &b, &c);
    getchar();
    getchar();
    return 0;
}
void address(float * a, float * b, float * c)
{
    float temp = *a, temp_2 = *b, temp_3 = *c;
    number_1(&temp, &temp_2, &temp_3);
    number_2(&temp, &temp_2, &temp_3);
}
void number_1(float * temp, float * temp_2, float * temp_3)
{
    if(temp < temp_2 && temp < temp_3)
        printf("%p, ", &temp);
    else if(temp_2 < temp && temp_2 < temp_3)
        printf("%p, ", &temp_2);
    else
        printf("%p, ", &temp_3);
}
void number_2(float * temp, float * temp_2, float * temp_3)
{
    if(temp );
}
