/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */

ListNode* reverse(ListNode* l, ListNode* r)
{
    ListNode* p = r; // neat trick
    ListNode* c = l;
    ListNode* n = l->next;
            
    while(n != r)
    {
        c->next = p;
        p = c;
        c = n;
        n = n->next;
    }
    c->next = p;
    
    return c;
}

ListNode* Solution::reverseBetween(ListNode* head, int left, int right)
{
    // corner cases
    if(head->next == NULL || left == right) 
        return head;
    
    // setting the left ptr and left left ptr
    ListNode* l = head;
    ListNode* ll = head;
    while(left > 2)
    {
        l = l->next;
        left--;
    }
    
    ll = l;
    l = l->next;
                    
    // setting the right ptr
    ListNode* r = head;
    while(--right)
        r = r->next;
    
    // for left == 1 corner case
    if(left == 1)
        return reverse(head, r->next);
    
    r = reverse(l, r->next);   
    ll->next = r;
        
    return head;
}