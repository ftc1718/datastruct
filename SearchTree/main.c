#include <stdio.h>
#include "SearchTree.h"

int main()
{
    SearchTree T;
  //  int i;
 //   TreeNode *p;
    T = MakeEmpty(NULL);
 //   for(i = 0; i < 50; i += 2)
 //       T = Insert(i, T);
    T = Insert(7, T);
    T = Insert(2, T);
    T = Insert(8, T);
    T = Insert(1, T);
    T = Insert(6, T);
    T = Insert(4, T);
    T = Insert(3, T);
    T = Insert(5, T);
    printf("before del\n");
    PrintTree(T);
    T = Delete(2, T);
    printf("\nafter del\n");
    PrintTree(T);
    return 0;
}
