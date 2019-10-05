#include <stdio.h>
char get_first(void);
char function(void);
float get_float(void);
int main(void)
{
    float number_1, number_2;
    char ch;
    ch = function();
    while(ch != 'q')
    {
        printf("Enter first number:\n");
        number_1 = get_float();
        printf("Enter second number:\n");
        number_2 = get_float();
        if(ch == 'a')
        {
            printf("%.2f + %.2f = %.2f\n", number_1 , number_2 , number_1 + number_2);
        }
        else if(ch == 's')
        {
            printf("%.2f - %.2f = %.2f\n", number_1 , number_2 , number_1 - number_2);
        }
        else if(ch == 'm')
        {
            printf("%.2f * %.2f = %.2f\n", number_1 , number_2 , number_1 * number_2);
        }
        else if(ch == 'd')
        {
            printf("%.2f / %.2f = %.2f\n", number_1 , number_2 , number_1 / number_2);
        }
        ch = function();
    }
    getchar();
    getchar();
    return 0;
}
float get_float(void)
{
    float input;
    char ch;
    while(scanf("%f", &input) != 1)
    {
        while((ch = getchar()) != '\n')
            putchar(ch);
        printf(" is not a float.\nPlease enter a float, ");
        printf("such as 2.5, -1.78E8, or 3: \n");
    }
    getchar();
    return input;
}
char function(void)
{
    char ch;
    printf("Enter the operation of your choice:\n");
    printf("a. add           s. subtract\n");
    printf("m. multiply      d. divide\n");                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                            
    printf("q. quit\n");
    ch = get_first();
    while(ch != 'a'&&ch != 's'&&ch != 'm'&&ch != 'd'&&ch != 'q')  
    {
        printf("Please respond with a, s, m, d, or q:\n");
        ch = get_first();
    }
    return ch;
}
char get_first(void)
{
    char ch;
    ch = getchar();
    while(getchar() != '\n')
    {
        continue;
    }
    return ch;
}



































































































































































































































































