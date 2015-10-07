#ifndef AVLTREE_H_INCLUDED
#define AVLTREE_H_INCLUDED

typedef
struct node
{
    int val;
    struct node *left;
    struct node *right;
    int height;
}TreeNode, *AvlTree;

AvlTree MakeEmpty(AvlTree T);
TreeNode* Find(int x, AvlTree T);
TreeNode* FindMin(AvlTree T);
TreeNode* FindMax(AvlTree T);
AvlTree Insert(int x, AvlTree T);
AvlTree Delete(int x, AvlTree T);
int Retrieve(TreeNode *p);

#endif // AVLTREE_H_INCLUDED
