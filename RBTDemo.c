#include <stdio.h>
#include <stdlib.h>

#include "RedBlackTree.h"

#define LENGTH 10

int main(void)
{
    Node * root = NULL;

    for(int i = 0; i < LENGTH; i++)
    {
        Node * n = NULL;
        n = (Node *) malloc(sizeof(Node));
        n->key = i;
        root = Insert(root, n);
    }
    PrintTree(root);
    getchar();
    return 0;
}