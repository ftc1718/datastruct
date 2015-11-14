/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */

void divideList(struct ListNode **la, struct ListNode **lb)
{
    struct ListNode *fast, *slow;
    struct ListNode *pre = *la;
    fast = slow = *la;
    while(slow && slow->next)
    {
        pre = fast;
        fast = fast->next;
        slow = slow->next->next;
    }
    pre->next = NULL;
    *lb = fast;
}

void merge(struct ListNode **head, struct ListNode **tail)
{
    struct ListNode *p = *head, *q = *tail;
    struct ListNode *pre = NULL;
    if(p->val < q->val)
    {
        *head = p;
        p = p->next;
    }
    else
    {
        *head = q;
        q = q->next;
    }
    pre = *head;
    while(p && q)
    {
        if(p->val < q->val)
        {
            pre->next = p;
            p = p->next;
        }
        else
        {
            pre->next = q;
            q = q->next;
        }
        pre = pre->next;
    }
    if(q)
        p = q;
    while(p)
    {
        pre->next = p;
        pre = p;
        p = p->next;
    }
//    pre->next = NULL;
}

void mergeSort(struct ListNode **head)
{
    if(*head && (*head)->next)
    {
        struct ListNode *tail = NULL;
        divideList(head, &tail);
        mergeSort(head);
        mergeSort(&tail);
        merge(head, &tail);
    }
}

struct ListNode* sortList(struct ListNode* head) {
    mergeSort(&head);
    return head;
}