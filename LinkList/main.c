#include "Linklist.h"
#include <stdio.h>
#include <stdlib.h>

int main()
{
    Linklist L;
    Initlist(&L);
    Insertlist(&L, 15);
    Insertlist(&L, 2);
    Insertlist(&L, 100);
    Printlist(L);
    return 0;
}
