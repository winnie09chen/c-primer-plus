#include <stdio.h>
#include <stdlib.h>

#include "RedBlackTree.h"

#define LENGTH 20

int main(void)
{
    Node * root = NULL;
    Node * temp = NULL;
    for(int i = 0; i < LENGTH; i++)
    {
        Node * n = NULL;
        n = (Node *) malloc(sizeof(Node));
        n->key = i;
        root = Insert(root, n);
    }
    PrintTree(root);
    temp = FindNode(root, 11);
    printf("%d (%p)\n", temp->key, temp);
    DeleteNode(temp);
    PrintTree(root);
    getchar();
    return 0;
}