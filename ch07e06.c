#include <stdio.h>
int main(void)
{
    char ch_1, pch_1;
    int ei = 0;
    printf("Input a setence:\n");
    while((ch_1 = getchar()) != '#')
    {
        if(ch_1 == 'i' && pch_1 == 'e')
        {
            ++ei;
        }        
        pch_1 = ch_1;
    }
    printf("ei: %d\n", ei);
    getchar();
    getchar();
    return 0;
}