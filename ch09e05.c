#include <stdio.h>
float larger_of(float a, float b);
int main(void)
{
    float a = 3.1415, b = 2.6942;
    printf("%f  %f\n", a, b);
    larger_of(a, b);
    a = larger_of(a, b);
    b = larger_of(a, b);
    printf("%f  %f\n", a, b);
    getchar();
    getchar();
    return 0;
}
float larger_of(float a, float b)
{
    float bigger;
    if(a > b)
    {
        bigger = a;
        return bigger;
    }
    else
    {
        bigger = b;
        return bigger;
    }
}
