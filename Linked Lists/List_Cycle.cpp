/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
ListNode* Solution::detectCycle(ListNode* head)
{
    // corner cases        
    if(head == NULL || head->next == NULL) return NULL;
    
    ListNode* s = head->next;
    ListNode* f = head->next->next;

    /* 
        Floyd's algorithm 
        
        1) find the slow and fast ptr meeting point
        2) set fast ptr to hear, and append both with same speed
        3) where ever they meet is the beginning of a loop
    */
    
    while(f != s)
    {
        if(f == NULL || f->next == NULL) return NULL; // No cycle 

        s = s->next;
        f = f->next->next;
    }

    f = head;

    while(f != s)
    {
        f = f->next;
        s = s->next;
    }

    return f;
}