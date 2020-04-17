#ifndef LIST_H_
#define LIST_H_
#include <stdbool.h>

#define TSIZE 45
struct film
{
    char title[TSIZE];
    int rating;
};

typedef struct film Item;

typedef struct node
{
    Item item;
    struct node * prev;
    struct node * next;
} Node;

typedef struct list
{
    struct node * head;
    struct node * tail;
    int size;
} List;

void InitializeList(List * plist);

bool ListIsEmpty(const List * plist);

bool ListIsFull(const List * plist);

unsigned int ListItemCount(const List * plist);

bool AddItemTail(Item item, List * plist);

bool AddItemHead(Item item, List * plist);

void Traverse(const List * plist, void(*pfun)(Item item));

void ReverseTraverse(const List * plist, void(*pfun)(Item item));

void EmptyTheList(List * plist);

bool DeleteItemHead(List * plist, Item * item);

bool DeleteItemTail(List * plist, Item * item);

#endif
