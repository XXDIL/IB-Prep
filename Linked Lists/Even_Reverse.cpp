/* 
    IMO just use a stack or a vector.

    But if you want O(1) space:
        1) split even and odd nodes
        2) reverse the even list
        3) merge the lists
*/
ListNode* Solution::solve(ListNode* o)
{
    ListNode* e = o->next;
    ListNode* h1 = o;
    ListNode* h2 = e;

    // split even and odd nodes
    while(h1!=NULL && h2!=NULL)
    {
        if(h1 && h1->next)
        {
            h1->next = h1->next->next;
            h1 = h1->next;
        }
        if(h2 && h2->next)
        {
            h2->next = h2->next->next;
            h2 = h2->next;
        }
    }

    // reverse the even list if len(e) > 1
    if(e && e->next)
    {
        ListNode* p = NULL;
        h1 = e->next; // next

        while(h1)
        {
            e->next = p;
            p = e;
            e = h1;

            h1 = h1->next;
        }

        e->next = p;
    }

    // merge the lists
    h1 = o;
    h2 = o->next;
    while(h2)
    {
        h1->next = e;
        h1 = e->next;
        e->next = h2;

        e = h1;
        h1 = h2;
        h2 = h2->next; 
    }

    if(e)
        h1->next = e;

    return o;
}