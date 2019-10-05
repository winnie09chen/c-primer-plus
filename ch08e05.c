#include <stdio.h>
int main(void)
{
    int guess = 50, a = 100, b = 1;
    char ch = 'a';
    printf("Pick an integer from 1 to 100. I will try to guess. If I guess too big, please input 'b'. If I guess too small, please input 's'. If I guess right, please input 'y'.\n ");
    while(ch != 'q')
    {
        if(ch == 'y')
        {
            printf("Thanks for playing.\n");
            break;
        }
        else
        {   
            printf("Is your number %d?\n", guess);
            scanf("%c", &ch);
            getchar();
            if(ch == 's')
            {
                b = guess;
                guess = (a + b) / 2;
                
            }
            else if(ch == 'b')
            {
                a = guess;
                guess = (a + b) / 2;
            }   
        } 
    }
    getchar();
    getchar();
    return 0;
}