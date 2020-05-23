#ifndef __REDBLACKTREE_H
#define __REDBALCKTREE_H

#include <assert.h>
#include <stdlib.h>

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

#endif