#include <stdio.h>


int input_float(float *f, char *prefix);

int input_two_floats(float *fa, float *fb);

int main(void)
{
    int scanf_count;
    float number_1, number_2;
    scanf_count = input_two_floats(&number_1, &number_2);
    while (scanf_count == 2)
    {
        printf("%f\n", (number_1-number_2)/(number_1*number_2));
        scanf_count = input_two_floats(&number_1, &number_2);
    }
    getchar();
    getchar();
    return 0;
}

int input_float(float *f, char *prefix)
{
    printf("Input %s float:\n", prefix);
    return scanf("%f", f);
}

int input_two_floats(float *fa, float *fb)
{
    return input_float(fa, "a") + input_float(fb, "another"); 
}