#include <stdio.h>
#include <stdlib.h>
#include "Stack.h"

static void CopyToNode(Item item, Node * pnode);

static void FreeNode(Item item, Node * pnode);

void InitializeStack(Stack * pstack)
{
    *pstack = NULL;
}

bool StackIsFull(const Stack * pstack)
{
    Node * pt;
    bool full;

    pt = (Node *)malloc(sizeof(Node));
    full = pt == NULL;
    free(pt);

    return full;
}

bool AddItem(Item item, Stack * pstack)
{
    Node * pnew;
    pnew = (Node *)malloc(sizeof(Node));
    if(pnew == NULL)
    {
        return false;
    }

    CopyToNode(item, pnew);
    pnew->next = *pstack;
    *pstack = pnew; 
    return true;
}

void Traverse(const Stack * plist, void(*pfun)(Item item, Node * pnode))
{
    Node * pnode = *plist;
    Node * ptemp = NULL;
    while(pnode != NULL)
    {
        ptemp = pnode;
        pnode = pnode->next;
        (*pfun)(ptemp->item, ptemp);
    }
}

void EmptyTheStack(Stack * pstack)
{
    Traverse(pstack, FreeNode);
}

static void CopyToNode(Item item, Node * pnode)
{
    pnode->item = item;
}

static void FreeNode(Item item, Node * pnode)
{
    free(pnode);
}

bool StackIsEmpty(const Stack * pstack)
{
    if(*pstack == NULL)
    {
        return true;
    }
    else
    {
        return false;
    }
    
}

