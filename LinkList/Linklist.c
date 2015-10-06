#include "Linklist.h"
#include <stdio.h>
#include <stdlib.h>

void Initlist(Linklist *L)
{
    (*L) = (Linklist)malloc(sizeof(Linknode));
    (*L)->next = NULL;
}

void Insertlist(Linklist *L, int data)
{
    Linknode *p = (Linknode*)malloc(sizeof(Linknode));
    p->val = data;
    p->next = (*L)->next;
    (*L)->next = p;
}

void Printlist(Linklist L)
{
    Linknode *p = L->next;
    while(p)
    {
        printf("%d\n", p->val);
        p = p->next;
    }
}
