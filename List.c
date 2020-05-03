#include <stdio.h>
#include <stdlib.h>
#include "List.h"


void InitializeList(List * plist)
{
    plist->head = NULL;
    plist->tail = NULL;
}

bool ListIsEmpty(const List * plist)
{
    return plist->head == NULL;
}

bool ListIsFull(const List * plist)
{
    Node * pt;
    bool full;

    pt = (Node *)malloc(sizeof(Node));
    full = pt == NULL;
    free(pt);
    return full;
}

unsigned int ListItemCount(const List * plist)
{
    return plist->size;
}

bool AddItemTail(Item item, List * plist)
{
    Node * pnew;

    pnew = (Node *)malloc(sizeof(Node));

    if(pnew == NULL)
    {
        return false;
    }

    pnew->item = item;
    pnew->next = NULL;
    pnew->prev = NULL;

    if(plist->head == NULL)
    {
        plist->head = pnew;
        plist->tail = pnew;
    }
    else
    {
        plist->tail->next = pnew;
        pnew->prev = plist->tail;
        plist->tail = pnew;
    }
    plist->size++;

    return true;
}

void Traverse(const List * plist, void(*pfun)(Item item))
{
    Node * pnode = plist->head;

    while(pnode != NULL)
    {
        (*pfun)(pnode->item);
        pnode = pnode->next;
    }
}

void ReverseTraverse(const List * plist, void(*pfun)(Item item))
{
    Node * pnode = plist->tail;

    while(pnode != NULL)
    {
        (*pfun)(pnode->item);
        pnode = pnode->prev;
    }
}

void EmptyTheList(List * plist)
{
    Node * pnode = plist->head;
    Node * temp;
    
    while(pnode != NULL)
    {
        temp = pnode->next;
        free(pnode);
        pnode = temp;
    }

    plist->head = NULL;
    plist->tail = NULL;
}

bool AddItemHead(Item item, List * plist)
{
    Node * ptemp;
    ptemp = (Node *)malloc(sizeof(Node));

    if(ptemp == NULL)
    {
        return false;
    }

    ptemp->item = item;;
    ptemp->next = NULL;

    if(plist->head == NULL)
    {
        plist->head = ptemp;
        plist->tail = ptemp;
        ptemp->next = NULL;
        ptemp->prev = NULL;
    }
    else
    {
        ptemp->next = plist->head;
        ptemp->prev = NULL;
        plist->head->prev = ptemp;
        plist->head = ptemp;
    }
    plist->size++;
    return true;
}

static bool DeleteItem(List * plist, Item * pitem, bool from_head)
{
    Node * ptemp;
    if(ListIsEmpty(plist))
    {
        return false;
    }
    else
    {
        ptemp = from_head ? plist->head : plist->tail;
        *pitem = ptemp->item;
        if (from_head)
        {
            plist->head = ptemp->next;
            plist->head->prev = NULL;

        }
        else
        {
            plist->tail = ptemp->prev;
            plist->tail->next = NULL;
        }
        free(ptemp);
    }
    plist->size--;
    return true;    
}

bool DeleteItemHead(List * plist, Item * pitem)
{
    return DeleteItem(plist, pitem, true);
}

bool DeleteItemTail(List * plist, Item * pitem)
{
    return DeleteItem(plist, pitem, false);
}

bool IsCycle(List * plist)
{
    Node * p1;
    Node * p2;
    p1 = plist->head;
    p2 = plist->head;

    while(p2 != NULL && p2->next != NULL)
    {
        p1 = p1->next;
        p2 = p2->next->next;

        if(p1 == p2)
        {
            return true;
        }
    }

    return false;
}