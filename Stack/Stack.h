#ifndef STACK_H_INCLUDED
#define STACK_H_INCLUDED
typedef
struct node{
    int val;
    struct node* next;
}Stacknode, *Stack;

void InitStack(Stack *S);
int isEmpty(Stack S);
int getTop(Stack S);
void push(Stack *S, int data);
void pop(Stack *S, int *data);
void DestoryStack(Stack *S);

#endif // STACK_H_INCLUDED
