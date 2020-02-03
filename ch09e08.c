#include <stdio.h>
float power(float n, int m);
int main(void)
{
    float n, j;
    int m;
    printf("Input a number:\n");
    scanf("%f", &n);
    printf("Input a number:\n");
    scanf("%d", &m);
    j = power(n, m);
    printf("%.2f", j);
    getchar();
    getchar();
    return 0;
}
float power(float n, int m)
{
    float k = 1;
    if(m == 0)
    {
        return 1;
    }
    for(int a = 1; a <= m; a++)
    {
        k *= n;
    }
    return k;
}