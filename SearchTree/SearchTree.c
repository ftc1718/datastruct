#include "SearchTree.h"
#include "fatal.h"

SearchTree MakeEmpty(SearchTree T)
{
    if(T != NULL)
    {
        MakeEmpty(T->left);
        MakeEmpty(T->right);
        free(T);
    }
    return NULL;
}

TreeNode *Find(int x, SearchTree T)
{
    if(T == NULL)
        return NULL;
    if(x < T->val)
        return Find(x, T->left);
    else if(x > T->val)
        return Find(x, T->right);
    else
        return T;
}

SearchTree Insert(int x, SearchTree T)
{
    if(T == NULL)
    {
        T = (SearchTree)malloc(sizeof(TreeNode));
        if(T == NULL)
            FatalError("Out of space!!!");
        else
        {
            T->val = x;
            T->left = T->right = NULL;
        }
    }
    else if(x < T->val)
    {
        T->left = Insert(x, T->left);
    }
    else if(x > T->val)
    {
        T->right = Insert(x, T->right);
    }
    /* else x is in the tree already; we'll do nothing */
    return T;
}

TreeNode *FindMin(SearchTree T)
{
    if(T != NULL)
        while(T->left)
            T = T->left;
    return T;
}

TreeNode *FindMax(SearchTree T)
{
    if(T != NULL)
        while(T->right)
            T= T->right;
    return T;
}

SearchTree DeleteMin(int *min, SearchTree T)
{
    TreeNode *Tmp;
    TreeNode *pre = T;
    if(T->left == NULL)
    {
        *min = T->val;
        return T->right;
    }

    Tmp = T->left;
    while(Tmp->left)
    {
        Tmp = Tmp->left;
        pre = pre->left;
    }

    *min = Tmp->val;
    pre->left = Tmp->right;
    free(Tmp);
    return T;
}

SearchTree Delete(int x, SearchTree T)
{
    TreeNode *TmpCell;
    int min;
    if(T == NULL)
        Error("Element not found");
    else if(x < T->val)
    {
        T->left = Delete(x, T->left);
    }
    else if(x > T->val)
    {
        T->right = Delete(x, T->right);
    }
    else
    {
        if(T->left && T->right)
        {
            T->right = DeleteMin(&min, T->right);
            T->val = min;
        }
        else
        {
            TmpCell = T;
            if(T->left == NULL)
                T = T->right;
            else if(T->right == NULL)
                T = T->left;
            free(TmpCell);
        }
    }
    return T;
}

//SearchTree Delete(int x, SearchTree T)
//{
//    TreeNode *TmpCell;
//    if(T == NULL)
//        Error("Element not found");
//    else if(x < T->val)
//    {
//        T->left = Delete(x, T->left);
//    }
//    else if(x > T->val)
//    {
//        T->right = Delete(x, T->right);
//    }
//    else
//    {
//        if(T->left && T->right)
//        {
//            TmpCell = FindMin(T->right);
//            T->val = TmpCell->val;
//            T->right = Delete(T->val, T->right);
//        }
//        else
//        {
//            TmpCell = T;
//            if(T->left == NULL)
//                T = T->right;
//            else if(T->right == NULL)
//                T = T->left;
//            free(TmpCell);
//        }
//    }
//    return T;
//}
int Retrieve(TreeNode *p)
{
    return p->val;
}

void PrintTree(SearchTree T)
{
    if(T)
    {
        PrintTree(T->left);
        printf("%d ", T->val);
        PrintTree(T->right);
    }
}
