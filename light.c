#include <stdio.h>
#define SIZE 4
int main(void)
{
    int light, choose;
    int lights[SIZE] = {1, 1, 1, 1};
    char ch;
    printf("Do you want to quit(q): ");
    scanf("%c", &ch);
    getchar();
    while(ch != 'q')
    {
        a: printf("Which light do you want to change(1 - 4): ");
        scanf("%d", &light);
        getchar();
        if(light > 4)
        {
            printf("There is no light with this number.\n");
            goto a;
        }
        b: printf("Do you want to open or close(0 / 1): ");
        scanf("%d", &choose);
        getchar();
        if(choose < 0 && choose > 1)
        {
            printf("Please choose again.\n");
            goto b;
        }
        lights[light - 1] = choose;
        for(int i = 0; i < SIZE; i++)
        {
            if(lights[i] == 0)
            {
                printf("ON ");
            }
            else
            {
                printf("OFF ");
            }
        }
        printf("\n");
        printf("Do you want to quit(q): ");
        scanf("%c", &ch);
        getchar();
    }
    getchar();
    getchar();
    return 0;
}
