#include <stdio.h>
#include <string.h>
int main(void)
{
    char firstname[20];
    char lastname[20];
    printf("What is your first name?\n");
    scanf("%s", firstname);
    printf("What is your last name?\n");
    scanf("%s", lastname);
    printf("%s %s\n", firstname, lastname);
    printf("%*d %*d", strlen(firstname), strlen(firstname), strlen(lastname), strlen(lastname));
    getchar();
    getchar();
    return 0;
}