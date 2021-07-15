/* 
    looks complex (as usual) but contains the following steps:
        1) find mid point and split them
        2) reverse from mid to end
        3) traverse from back and front and keep fprming links
*/
ListNode* Solution::reorderList(ListNode* h)
{
    if(h->next == NULL)
        return h;
    
    ListNode* a = h;
    ListNode* b = h;
    
    // find the node just b4 mid node
    while(b->next && b->next->next)
    {
        a = a->next;
        b = b->next->next;
    }
    
    // reverese from mid to end
    ListNode* p = NULL;
    b = a->next;
    
    // splitting the 2 lists
    a->next = NULL;
    
    a = b->next;
    
    while(a)
    {
        b->next = p;
        p = b;
        b = a;
        a = a->next;
    }
    b->next = p;
    
    // main logic (appending nodes in an alternate order)
    a = h;
    while(b)
    {
        p = b;
        b = b->next;
        
        p->next = a->next;
        a->next = p;
        
        a = a->next->next;
    }

    return h;
}