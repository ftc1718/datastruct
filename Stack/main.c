#include "Stack.h"
#include <stdio.h>
#include <stdlib.h>

int main()
{
    Stack s;
    int valTop, valpop;
    InitStack(&s);
    if(isEmpty(s))
        printf("isempty\n");
    else
        printf("notempty\n");
    push(&s, 12);
    if(isEmpty(s))
        printf("isempty\n");
    else
        printf("notempty\n");
    push(&s, 11);
    push(&s, 10);
    pop(&s, &valpop);
    valTop = getTop(s);
    printf("top = %d\n", valTop);
    printf("popval = %d\n", valpop);
    return 0;
}
