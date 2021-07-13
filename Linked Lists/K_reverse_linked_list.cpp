/* 
    Reverse a link list between begin and end "exclusively".
    an example:

    a linked list:
        0->1->2->3->4->5->6
        |           |   
        a           b

    after call begin = reverse(begin, end)
        
        0->3->2->1->4->5->6
                |  |
                a  b
 */
ListNode* Solution::reverseList(ListNode* h, int B)
{
    if(B == 1)
        return h;
    
    ListNode* dummy = new ListNode(0);
    dummy->next = h;
    
    ListNode* a=dummy;
    ListNode* b=h;
    
    while(b)
    {
        int i = 0;
        while(i < B)
        {
            b = b->next;
            i++;
        }

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
        h = b;
    }
    
    return dummy->next;
}