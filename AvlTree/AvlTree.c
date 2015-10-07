#include "AvlTree.h"
#include "fatal.h"

AvlTree MakeEmpty(AvlTree T)
{
    if(T)
    {
        MakeEmpty(T->left);
        MakeEmpty(T->right);
        free(T);
    }
    return NULL;
}

TreeNode* Find(int x, AvlTree T)
{
    if(x < T->val)
        return Find(x, T->left);
    else if(x > T->val)
        return Find(x, T->right);
    else
        return T;
}

TreeNode* FindMin(AvlTree T)
{
    if(T)
        while(T->left)
            T = T->left;
    return T;
}

TreeNode* FindMax(AvlTree T)
{
    if(T)
        while(T->right)
            T = T->right;
    return T;
}

static int Height(TreeNode *p)
{
    if(p == NULL)
        return -1;
    else
        return p->height;
}

static int Max(int Lhs, int Rhs)
{
    return Lhs > Rhs ? Lhs : Rhs;
}

static TreeNode*
SingleRotateWithLeft(TreeNode *k2)
{
    TreeNode *k1;
    k1 = k2->left;
    k2->left = k1->right;
    k1->right = k2;
    k2->height = Max(Height(k2->left), Height(k2->right)) + 1;
    k1->height = Max(Height(k1->left), k2->height) + 1;
    return k1;
}

static TreeNode*
SingleRotateWithRight(TreeNode *k1)
{
    TreeNode *k2;
    k2 = k1->right;
    k1->right = k2->left;
    k2->left = k1;
    k1->height = Max(Height(k1->left), Height(k1->right)) + 1;
    k2->height = Max(k1->height, Height(k2->right)) + 1;
    return k2;
}

static TreeNode*
DoubleRotateWithLeft(TreeNode *k3)
{
    k3->left = SingleRotateWithRight(k3->left);
    return SingleRotateWithLeft(k3);
}

static TreeNode*
DoubleRotateWithRight(TreeNode *k4)
{
    k4->right = SingleRotateWithLeft(k4->right);
    return SingleRotateWithRight(k4);
}

AvlTree Insert(int x, AvlTree T)
{
    if(T == NULL)
    {
        T = (TreeNode*)malloc(sizeof(TreeNode));
        if(T == NULL)
            FatalError("Out of space!!!");
        else
        {
            T->val = x;
            T->height = 0;
            T->left = T->right = NULL;
        }
    }
    else if(x < T->val)
    {
        T->left = Insert(x, T->left);
        if(Height(T->left) - Height(T->right) == 2)
        {
            if(x < T->left->val)
                T = SingleRotateWithLeft(T);
            else
                T = DoubleRotateWithLeft(T);
        }

    }
    else if(x > T->val)
    {
        T->right = Insert(x, T->right);
        if(Height(T->right) - Height(T->left) == 2)
        {
            if(x > T->right->val)
                T = SingleRotateWithRight(T);
            else
                T = DoubleRotateWithRight(T);
        }

    }
    // else x is in the tree already; we'll do nothing

    T->height = Max(Height(T->left), Height(T->right)) + 1;
    return T;
}

AvlTree Delete(int x, AvlTree T)
{
    printf("Unimplemented; %d remains\n", x);
    return T;
}

int Retrieve(TreeNode *p)
{
    return p->val;
}
