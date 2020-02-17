#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define NAME_SIZE 20
#define PEOPLE_SIZE 5

int main(void)
{
    struct name
    {
        char * first_name;
        char * middle_name;
        char * last_name;
    };

    struct insurance
    {
        int number;
        struct name person;
    };

    struct insurance people[PEOPLE_SIZE];
    
    for(int i = 0; i < PEOPLE_SIZE; i++) 
    {
        people[i].person.first_name = (char *)malloc(NAME_SIZE * sizeof(char));
        people[i].person.middle_name = (char *)malloc(NAME_SIZE * sizeof(char));
        people[i].person.last_name = (char *)malloc(NAME_SIZE * sizeof(char));
    }
    
    for(int i = 0; i < PEOPLE_SIZE; i++) 
    {
        printf("Enter the %d people's insurance number: ", i + 1);
        scanf("%d", &people[i].number);
        printf("Enter the %d people's name: ", i + 1);
        scanf("%s %s", people[i].person.first_name, people[i].person.last_name);
        printf("Does the %d people have middle name(middle name or 1): ", i + 1);
        scanf("%s", people[i].person.middle_name);
    }

    for(int i = 0; i < PEOPLE_SIZE; i++)
    {
        if(strcmp(people[i].person.middle_name, "1") != 0)
        {
            printf("%s %s %c. -- %d\n", people[i].person.first_name, people[i].person.last_name, people[i].person.middle_name[0], people[i].number);
        }
        else if(strcmp(people[i].person.middle_name, "1") == 0)
        {
            printf("%s %s -- %d\n", people[i].person.first_name, people[i].person.last_name, people[i].number);
        }
    }

    getchar();
    getchar();
    return 0;
}