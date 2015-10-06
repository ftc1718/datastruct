#include <stdio.h>
#include <stdlib.h>
typedef
 struct Node{
     int val;
     struct Node *next;
 }Stacknode, *Stack;
void initStack(Stack *S)
{
    (*S) = (Stack)malloc(sizeof(Stacknode));
    (*S)->next = NULL;
}
int isEmpty(Stack S)
{
    if(S->next == NULL)
        return 1;
    else
        return 0;
}
void push(Stack *S, int node)
{
    Stacknode *s;
    s = (Stacknode *)malloc(sizeof(Stacknode));
    s->val = node;
    s->next = (*S)->next;
    (*S)->next = s;

}
void pop(Stack *S, int *node)
{
    Stacknode *s;
    s = (*S)->next;
    (*S)->next = s->next;
    *node = s->val;
    free(s);
//9    printf("val in pop %d\n", (*node)->val);
}
void destroyStack(Stack *S)
{
    int node;
    while(!isEmpty(*S))
        pop(S, &node);
    printf("in destroy\n");
    free(*S);
}
int main()
{
    Stack S;
    int data;
    initStack(&S);
    push(&S, 1);
    push(&S, 2);
    pop(&S, &data);
    printf("data = %d\n", data);
    pop(&S, &data);
    printf("data = %d\n", data);
    push(&S, 3);
    pop(&S, &data);
    printf("data = %d\n", data);
    if(!isEmpty(S))
        printf("not empty\n");
    else
        printf("empty\n");
    destroyStack(&S);
    return 0;
}
