/* Similar to insertion sort code */
ListNode* Solution::partition(ListNode* h, int B)
{
    if(!h || !h->next)
        return h;
    
    ListNode* dummy = new ListNode(0);
    dummy->next = h;
    
    ListNode* x = dummy;
    while(x->next && x->next->val < B)
        x = x->next;
    
    ListNode* y = x->next;
            
    while(y)
    {
        while(y->next && y->next->val >= B)
            y = y->next;

        ListNode* temp = y->next;
        
        if(!temp)
            break;

        y->next = temp->next;
        temp->next = x->next;
        x->next = temp;
        x = x->next;
    }
            
    return dummy->next;
}