#ifndef SEARCHTREE_H_INCLUDED
#define SEARCHTREE_H_INCLUDED

typedef
struct node
{
    int val;
    struct node *left;
    struct node *right;
}TreeNode, *SearchTree;

SearchTree MakeEmpty(SearchTree T);
TreeNode *Find(int x, SearchTree T);
TreeNode *Findmin(SearchTree T);
TreeNode *Findmax(SearchTree T);
SearchTree Insert(int x, SearchTree T);
SearchTree Delete(int x, SearchTree T);
int Retrieve(TreeNode *p);
void PrintTree(SearchTree T);

#endif // SEARCHTREE_H_INCLUDED
