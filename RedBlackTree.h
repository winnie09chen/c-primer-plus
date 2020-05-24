#ifndef __REDBLACKTREE_H
#define __REDBALCKTREE_H

#include <assert.h>
#include <stdlib.h>
#include <stdbool.h>

enum color_t { BLACK, RED };

struct node {
    struct node * parent;
    struct node * left;
    struct node * right;
    enum color_t color;
    int key;
};

typedef struct node Node;


void InsertRepairTree(Node * n);

void DeleteCase1(Node * n);


Node * GetParent(Node *n) {
    return n == NULL ? NULL : n->parent;
}

Node * GetGrandParent(Node *n) {
    return GetParent(GetParent(n));
}

Node * GetSibling(Node *n) {
    Node *p = GetParent(n);
    if (p == NULL) {
        return NULL;
    }
    return n == p->left ? p->right : p->left;
}

Node * GetUncle(Node *n) {
    Node *p = GetParent(n);
    return GetSibling(p);
}

void RotateLeft(Node *n) {
    Node *nnew = n->right;
    Node *p = GetParent(n);
    assert(nnew != NULL);
    // rotate left
    n->right = nnew->left;
    nnew->left = n;
    n->parent = nnew;
    // fix n->right
    if (n->right != NULL) {
        n->right->parent = n;
    }
    // fix parent->child
    if (p != NULL) {
        if (n == p->left) {
            p->left = nnew;
        } else {
            p->right = nnew;
        }
    }
    nnew->parent = p;
}

void RotateRight(Node *n) {
    Node *nnew = n->left;
    Node *p = GetParent(n);
    assert(nnew != NULL);
    // rotate left
    n->left = nnew->right;
    nnew->right = n;
    n->parent = nnew;
    // fix n->left
    if (n->left != NULL) {
        n->left->parent = n;
    }
    // fix parent->child
    if (p != NULL) {
        if (n == p->left) {
            p->left = nnew;
        } else {
            p->right = nnew;
        }
    }
    nnew->parent = p;
}


void InsertRecurse(Node * root, Node * n) {
    if (root != NULL) {
        if (root->key > n->key) {
            if (root->left != NULL) {
                InsertRecurse(root->left, n);
                return;
            } else {
                root->left = n;
            }
        } else {
            if (root->right != NULL) {
                InsertRecurse(root->right, n);
                return;
            } else {
                root->right = n;
            }
        }
    }
    n->parent = root;
    n->left = n->right = NULL;
    n->color = RED;
}


void InsertCase1(Node * n) {
    n->color = BLACK;
}

void InsertCase2(Node * n) {
    return;
}

void InsertCase3(Node * n) {
    GetParent(n)->color = BLACK;
    GetUncle(n)->color = BLACK;
    GetGrandParent(n)->color = RED;
    InsertRepairTree(GetGrandParent(n));
}

void InsertCase4Step2(Node * n) {
    Node * p = GetParent(n);
    Node * g = GetGrandParent(n);
    if (n == p->left) {
        RotateRight(g);
    } else {
        RotateLeft(g);
    }
    p->color = BLACK;
    g->color = RED;
}

void InsertCase4(Node * n) {
    Node * p = GetParent(n);
    Node * g = GetGrandParent(n);

    if (n == p->right && p == g->left) {
        RotateLeft(p);
        n = n->left;
    } else if (n == p->left && p == g->right) {
        RotateRight(p);
        n = n->right;
    }

    InsertCase4Step2(n);
}

void InsertRepairTree(Node * n) {
    if (GetParent(n) == NULL) {
        InsertCase1(n);
    } else if (GetParent(n)->color == BLACK) {
        InsertCase2(n);
    } else if (GetUncle(n) != NULL && GetUncle(n)->color == RED) {
        InsertCase3(n);
    } else {
        InsertCase4(n);
    }
}

Node * Insert (Node * root, Node * n) {
    InsertRecurse(root, n);
    InsertRepairTree(n);
    // Find new root
    root = n;
    while (GetParent(root) != NULL) {
        root = GetParent(root);
    }
    return root;
}

void PrintTreeNode(Node * n, int level) {
    if (n == NULL) return;
    for(int i=0; i < 4 * level; i++) putchar(' ');
    printf("%d(%d)\n", n->key, n->color);
    PrintTreeNode(n->right, level+1);
    PrintTreeNode(n->left, level+1);
}

void PrintTree(Node * root)
{
    PrintTreeNode(root, 0);
}

void DeleteCase6(Node * n)
{
    Node * s = GetSibling(n);
    s->color = n->parent->color;
    n->parent->color = BLACK;

    if(n == n->parent->left)
    {
        s->right->color = BLACK;
        RotateLeft(n->parent);
    }
    else
    {
        s->left->color = BLACK;
        RotateRight(n->parent);
    }
} 

void DeleteCase5(Node * n)
{
    Node * s = GetSibling(n);

    if(s->color == BLACK)
    {
        if((n == n->parent->left) && (s->right->color == BLACK) && (s->left->color == RED))
        {
            s->color = RED;
            s->left->color = BLACK;
            RotateRight(s);
        }
        else if((n == n->parent->right) && (s->left->color == BLACK) && (s->right->color == RED))
        {
            s->color = RED;
            s->right->color = BLACK;
            RotateLeft(s);
        }
    }
    DeleteCase6(n);
}

void DeleteCase4(Node * n)
{
    Node * s = GetSibling(n);
    if((n->parent->color == RED) && (s->color == BLACK) && (s->left->color == BLACK) && (s->right->color == BLACK))
    {
        s->color = RED;
        n->parent->color = BLACK;
    }
    else
    {
        DeleteCase5(n);
    }
}

void DeleteCase3(Node * n)
{
    Node * s = GetSibling(n);
    if((n->parent->color == BLACK) && (s->color == BLACK) && (s->left->color == BLACK) && (s->right->color == BLACK))
    {
        s->color = RED;
        DeleteCase1(n->parent);
    }
    else
    {
        DeleteCase4(n);
    }
}

void DeleteCase2(Node * n)
{
    Node * s = GetSibling(n);

    if(s->color == RED)
    {
        n->parent->color = RED;
        s->color = BLACK;
        if(n == n->parent->left)
        {
            RotateLeft(n->parent);
        }
        else
        {
            RotateRight(n->parent);
        }
    }
    DeleteCase3(n);
}

void DeleteCase1(Node * n)
{
    if(n->parent != NULL)
    {
        DeleteCase2(n);
    }
}

void ReplaceNode(Node * n, Node * child)
{
    child->parent = n->parent;
    if(n == n->parent->left)
    {
        n->parent->left = child;
    }
    else
    {
        n->parent->right = child;
    }
}

Node * FindNode(Node * root, int key)
{
    if(root != NULL)
    {
        if(key < root->key)
        {
            return FindNode(root->left, key);
        }
        else if(key > root->key)
        {
            return FindNode(root->right, key);
        }
        else
        {
            return root;
        }
    }
    return NULL;
}

void DeleteOneNode(Node * n)
{
    Node * child = (n->right == NULL) ? n->left : n->right;
    assert(child);

    ReplaceNode(n, child);
    if(n->color == BLACK)
    {
        if(child->color == RED)
        {
            child->color = BLACK;
        }
        else
        {
            DeleteCase1(child);
        }
    }
    free(n);
}

Node * FindBiggest(Node *n)
{
    if (n->right != NULL)
    {
        return FindBiggest(n->right);
    }
    return n;
}


void DeleteTwoNodes(Node *n)
{
    Node * p = NULL;
    Node * left_n = NULL;
    left_n = FindBiggest(n->left);
    if (GetParent(left_n)->left == left_n)
    {
        GetParent(left_n)->left = left_n->left;
    }
    else
    {
        GetParent(left_n)->right =left_n->left;
    }
    if (left_n->left != NULL)
    {
        left_n->left->parent =  GetParent(left_n);
    }
    n->key = left_n->key;
    free(left_n);
}


void DeleteNode(Node * n)
{
    Node * p = GetParent(n);
    if (n->left != NULL && n->right != NULL)
    {
        DeleteTwoNodes(n);
    }
    else if (n->left == NULL && n->right == NULL)
    {
        if (p != NULL)
        {
            if (p->left == n) p->left = NULL;
            if (p->right == n) p->right = NULL;
        }
        free(n);
    }
    else
    {
        DeleteOneNode(n);
    }
}


#endif