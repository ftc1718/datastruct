#include "AvlTree.h"
#include <stdio.h>

void PrintTree(AvlTree T)
{
    if(T)
    {
        printf("%d ", T->val);
        PrintTree(T->left);
        PrintTree(T->right);
    }
}

int main()
{
    AvlTree T;
    T = MakeEmpty(NULL);
    T = Insert(1, T);
    T = Insert(2, T);
    T = Insert(3, T);
    PrintTree(T);
    return 0;
}
