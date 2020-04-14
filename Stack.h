#ifndef STACK_H_
#define STACK_H_
#define SIZE 40
#include <stdbool.h>


typedef char Item;

typedef struct node
{
    Item item;
    struct node * next;
} Node;

typedef Node * Stack;

void InitializeStack(Stack * pstack);

bool StackIsFull(const Stack * pstack);

bool AddItem(Item item, Stack * pstack);

void EmptyTheStack(Stack * pstack);

void Traverse(const Stack * plist, void(*pfun)(Item item, Node * pnode));

bool StackIsEmpty(const Stack * pstack);

#endif