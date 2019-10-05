#include <stdio.h>
int main(void)
{
    char ch;
    int number = 0;
    printf("Input a sentence:\n");
    while((ch = getchar()) != EOF)
    {
        if(ch >= 65 && ch <= 90 || ch >= 97 && ch <= 122)
        {
            printf("%d\n", ch);
        }
    }
    getchar();
    getchar();
    return 0;
}