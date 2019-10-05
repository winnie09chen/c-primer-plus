#include <stdio.h>


int main(void)
{
    char ch, ignore_ch;
    ch = getchar();
    while((ignore_ch = getchar()) != '\n')
    {
        printf("ignore: \"%c\" = %d\n", ignore_ch, ignore_ch);
    }

    printf("result: \"%c\" = %d\n", ch, ch);
    getchar();
    return 0;
}