#include <stdio.h>
int main(void)
{
    char ch;
    int count = 0;
    printf("Input a sentence:\n");
    while((ch = getchar()) != '#')
    {
        printf("%c: %d ",ch, ch);
        ++count;
        if(count % 8 == 0)
        {
            printf("\n");
        }
    }
    getchar();
    getchar();
    return 0;
}