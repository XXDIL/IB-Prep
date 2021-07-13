/* Similar to K_reverse_list.cpp juse a boolean rev variable is needed. */
ListNode* Solution::solve(ListNode* h, int B)
{
    if(B == 1)
        return h;
    
    ListNode* dummy = new ListNode(0);
    dummy->next = h;
    
    ListNode* a=dummy;
    ListNode* b=h;
    
    bool rev = 1;
    while(b)
    {
        int i = 0;
        while(i < B)
        {
            b = b->next;
            i++;
        }

        if(rev)
        {
            ListNode* p = b;
            ListNode* c = a->next;
            ListNode* n = c->next;

            while(n != b)
            {
                c->next = p;
                p = c;
                c = n;
                n = n->next;
            }
            c->next = p;
            a->next = c;

            a = h;
        }
        else
        {
            while(a->next != b)
                a = a->next;
        }

        h = b;
        
        rev = !rev;
    }
    
    return dummy->next;
}
