#include <stdio.h>
int main(void)
{
    int friends = 5, week = 1, leave = 1;
    printf("In the week %d, Rabund docter's has %d friends.\n", week, friends);
    while(friends <= 150) //150 is the Dumbar's number.
    {
        friends = (friends - leave)*2;
        ++week;
        ++leave;
        printf("In the week %d, Rabund docter's has %d friends.\n", week, friends);
    }
    getchar();
    return 0;
} 