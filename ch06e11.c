#include <stdio.h>

void reverse_number(int number[]);

void reverse_float(float f[], int l);

void print_float_array(float f[], int l);

int main(void)
{
    int number[8];
    for(int question_count = 0;question_count < 8;question_count++)
    {
        printf("Input a number:\n");
        scanf("%d", &number[question_count]);
    }
    reverse_number(number);
    for (int i = 0; i < 8; i++)
    {
        printf("%d", number[i]);
    }
    float f[] = {1.0,2.0,3.0,4.0};
    reverse_float(f, 4);
    print_float_array(f, 4);
    getchar();
    getchar();
    return 0;
}
void reverse_number(int number[])
{
    int tmp;
    int n = 8;
    for(int i=0, end=n/2; i<end; i++)
    {
        tmp = number[i];
        number[i] = number[n-1-i];
        number[n-1-i] = tmp;
    }
}
void reverse_float(float f[], int l)
{
    float tmp;
    for (int i = 0, end=l/2; i < end; i++)
    {
        tmp = f[i];
        f[i] = f[l-1-i];
        f[l-1-i] = tmp;
    }
}

void print_float_array(float f[], int l)
{
    for (size_t i = 0; i < l; i++)
    {
        printf("%f\n", f[i]);
    }
    
}