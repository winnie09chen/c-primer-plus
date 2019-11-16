#include <stdio.h>
void char_order(void);
int main(void)
{
    char ch;
    printf("Input a setence:\n");
    char_order();
    getchar();
    getchar();
    return 0;
}
void char_order(void)
{
    char ch;
    while((ch = getchar()) != EOF)
    {
        if(ch >= 'a' && ch <= 'z')
        {
            printf("%d, ", ch - 'a' + 1);
        }
        else if(ch >= 'A' && ch <= 'Z')
        {
            printf("%d, ", ch - 'A' + 1);
        }
    }
}




















