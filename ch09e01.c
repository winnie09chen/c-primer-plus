#include <stdio.h>
float less_double(float a, float b);
int main(void)
{
    float a, b;
    printf("Enter a pair of numbers:\n");
    while((scanf("%f %f", &a, &b)) == 2)
    {
        printf("The lesser of %f and %f is %f.\n", a, b, less_double(a, b));
        getchar();
        getchar();
        return 0;
    }
}
float less_double(float a, float b)
{
    float min;
    if(a < b)
    {
        min = a;
        return min;
    }
    else
    {
        min = b;
        return min;
    }
}