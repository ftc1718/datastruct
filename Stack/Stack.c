
#include "Stack.h"
#include <stdlib.h>

void InitStack(Stack *S){
    (*S) = (Stack)malloc(sizeof(Stacknode));
    (*S)->next = NULL;
}

int isEmpty(Stack S){
    if(!S->next)
        return 1;
    else
        return 0;
}

int getTop(Stack S){
    Stacknode *p = S;
    if(!p->next)
        exit(0);
    while(p->next)
        p = p->next;
    return p->val;
}

void push(Stack *S, int data){
    Stacknode *node = (Stacknode*)malloc(sizeof(Stacknode));
    Stacknode *p, *r;
    r = *S;
    p = (*S)->next;
    while(p)
    {
        r = p;
        p = p->next;

    }

    node->val = data;
    r->next = node;
    node->next = NULL;
}

void pop(Stack *S, int *data){
    Stacknode *q = *S;
    Stacknode *p = (*S)->next;
    if(!p)
        exit(0);
    while(p->next){
        q = p;
        p = p->next;
    }
    q->next = NULL;
    *data = p->val;
    free(p);
}
