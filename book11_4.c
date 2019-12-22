
#include <stdio.h>
#define SLEN 40
#define LTM 5
int main(void)
{
    const char *mytalents[LTM] = {
    "Adding numbers swiftly", 
    "Multiplying accurately", "Stashing data",
    "Following instructions to the letter",
    "Understanding the C language"
    };
    char yourtalents[LTM][SLEN] = {
    "Walking in a straight line", 
    "Sleeping", "Watching television",
    "Mailing letters", "Reading email"
    };
    int i;
    
    puts("Let's compare talents.");
    printf("%-36s %-25s\n", "My Talents", "Your Talents");
    for (i = 0; i < LTM; i++)
    {
        printf("%-36s %-25s\n", mytalents[i], yourtalents[i]);
    }
    printf("\nsizeof mytalents: %zd, sizeof yourtalents: %zd\n",
    sizeof(mytalents), sizeof(yourtalents));

    getchar();
    return 0;
}