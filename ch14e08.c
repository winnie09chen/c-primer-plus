#include <stdio.h>
#include <stdlib.h>

#define NAME_SIZE 20
#define PLANE_SIZE 12

struct seat
{
    char code;          // A-Z 
    short is_booked;    // 0 = not booked, 1 = booked
    char *first_name;   // frist name of customer
    char *last_name;    // last name of customer
};

int main(void)
{
    struct seat airplane[PLANE_SIZE];
    char ch = ' ';
    char choose;
    int count_empty_seats = 0;
    
    for(int i = 0; i < PLANE_SIZE; i++)
    {
        airplane[i].is_booked = 0;
        airplane[i].first_name = (char *)malloc(NAME_SIZE * sizeof(char));
        airplane[i].last_name = (char *)malloc(NAME_SIZE * sizeof(char));
        airplane[i].code = 'A' + i;
    }

    
    a: while(ch != 'f')
    {
        puts("To choose a function, enter its letter label:");
        puts("a) Show number of empty seats");
        puts("b) Show list of empty seats");
        puts("c) Show alphabetical list of seats");
        puts("d) Assign a customer to a seat assignment");
        puts("e) Delete a seat assignment");
        puts("f) quit");
        scanf("%c", &ch);
        getchar();

        if(ch == 'a')
        {
            for(int i = 0; i < PLANE_SIZE; i++)
            {
                if(airplane[i].is_booked == 0)
                {
                    ++count_empty_seats;
                }
            }
            printf("Empty seats: %d\n\n\n", count_empty_seats);
            count_empty_seats = 0;
        }

        if(ch == 'b')
        {
            for(int i = 0; i < PLANE_SIZE; i++)
            {
                if(airplane[i].is_booked == 0)
                {
                    printf("%c ", airplane[i].code);
                }
            }
            printf("\n");
        }

        if(ch == 'c')
        {
            for(int i = 0; i < PLANE_SIZE; i++)
            {
                if(airplane[i].is_booked == 0)
                {
                    printf("_  ");
                }
                else if(airplane[i].is_booked == 1)
                {
                    printf("X  ");
                }
            }

            printf("\n");

            for(int i = 0; i < PLANE_SIZE; i++)
            {
                printf("%c  ", airplane[i].code);
            }

            printf("\n");

            for(int i = 0; i < PLANE_SIZE; i++)
            {
                if(airplane[i].is_booked == 1)
                {
                    printf("%c. ", airplane[i].first_name[0]);
                }
                else
                {
                    printf("   ");
                }
            }

            printf("\n");
        }

        if(ch == 'd')
        {
            printf("What number of seat do you want to book (ENTER to quit): ");
            scanf("%c", &choose);
            getchar();

            if(choose == '\n')
            {
                goto a;
            }

            for(int i = 0; i < PLANE_SIZE; i++)
            {
                if(airplane[i].code == choose)
                {
                    if(airplane[i].is_booked == 1)
                    {
                        printf("This seat isn't empty.\n");
                        goto a;
                    }
                    else if(airplane[i].is_booked == 0)
                    {
                        printf("Finish book.\n");
                        airplane[i].is_booked = 1;
                        printf("What's your name: ");
                        scanf("%s %s", airplane[i].last_name, airplane[i].first_name);
                        getchar();
                        goto a;
                    }
                }
            }
        }
        
        if(ch == 'e')
        {
            printf("What number of seat do you want to delete (ENTER to quit): ");
            scanf("%c", &choose);
            getchar();
            for(int i = 0; i < PLANE_SIZE; i++)
            {
                if(airplane[i].code == choose)
                {
                    if(airplane[i].is_booked == 1)
                    {
                        airplane[i].is_booked = 0;
                        free(airplane[i].first_name);
                        free(airplane[i].last_name);
                        printf("Finish delete.\n");
                        goto a;
                    }
                    else if(airplane[i].is_booked == 0)
                    {
                        printf("This seat is empty.\n");
                        goto a;
                    }
                }
            }
        }
    }
    getchar();
    getchar();
    return 0;
}
