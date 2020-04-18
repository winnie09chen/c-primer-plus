#include <stdio.h>
#define NUMBER(A, B) (1 / (((1 / (A)) + (1 / (B))) / 2))
int main(void)
{
    float c = 0.5;
    float d = 0.25;
    printf("%.2f", NUMBER(c, d));
    getchar();
    getchar();
    return 0; 
}
