#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>
#include "Stack.h"

void show_char(Item item, Node * node);

void to_upper(Item item, Node * node);

int main(void)
{
    Stack string;
    Item temp;

    InitializeStack(&string);
    if(StackIsFull(&string))
    {
        fprintf(stderr, "No memory available! Bye!\n");
        exit(1);
    }

    puts("Enter a string: ");
    while((temp = getchar()) != '\n')
    {
        if(AddItem(temp, &string) == false)
        {
            fprintf(stderr, "Problems allocating memory.\n");
            break;
        }
        if(StackIsFull(&string) == true)
        {
            puts("The stack is full.\n");
            break;
        }
    }

    if(StackIsEmpty(&string) == true)
    {
        puts("No data entered.");
    }    
    else
    {
        puts("Here is the stack.");
        Traverse(&string, to_upper);
        Traverse(&string, show_char);
    }

    EmptyTheStack(&string);
    printf("\n");
    puts("Bye");

    getchar();
    getchar();
    return 0;
}

void show_char(Item item, Node * pnode)
{
    printf("%c", item);
}

void to_upper(Item item, Node * pnode)
{
    pnode->item = toupper(item);
}
