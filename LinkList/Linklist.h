#ifndef LINKLIST_H_INCLUDED
#define LINKLIST_H_INCLUDED

typedef
struct node{
    int val;
    struct node *next;
}Linknode, *Linklist;

void Initlist(Linklist *L);
void Insertlist(Linklist *L, int data);
//void Deletlist(Linklist *L, int data);
void Printlist(Linklist L);



#endif // LINKLIST_H_INCLUDED
