/* 
    simple logic : 
        1) use dummy head 
        2) x->next is the element that needs to be inserted
*/
ListNode* Solution::insertionSortList(ListNode* h)
{
    ListNode* dummy = new ListNode(-6000);
    dummy->next = h;
    ListNode* x = h;
    
    while(x->next)
    {
        ListNode* temp = x->next;
        ListNode* p = dummy;

        while(p->next != temp && p->next->val < temp->val)
            p = p->next;

        if(p->next != temp)
        {
            x->next = temp->next;
            temp->next = p->next;
            p->next = temp;
        }
        else // no need for insertion
            x = x->next;
    }
    
    return dummy->next;
}