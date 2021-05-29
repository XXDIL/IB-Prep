/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
 
ListNode* reverse(ListNode* h)
{
    ListNode* p = NULL;
    ListNode* c = h;
    ListNode* n = h->next;
    
    while(n)
    {
        c->next = p;
        p = c;
        c = n;
        n = n->next;    
    }
    c->next = p;
    
    return c;
}
 
int Solution::lPalin(ListNode* head)
{
    // finding the mid point
    ListNode* mid = head;
    ListNode* end = head;
    while(end && end->next)
    {
        mid = mid->next;
        end = end->next->next;
    }
    
    // reverse from mid to end
    ListNode* rh = reverse(mid);
    
    // compare rear head val to the head val untill they differ
    while(rh)
    {
        if(rh->val != head->val)
            return 0;
            
        rh = rh->next;
        head = head->next;
    }

    return 1;
}