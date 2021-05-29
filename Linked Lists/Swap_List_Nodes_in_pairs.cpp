/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */

/*
    use 3 pointer logic
    prev, curr, next
*/
 
ListNode* Solution::swapPairs(ListNode* head)
{
    // corner cases
    if(head == NULL || head->next == NULL) return head;
    
    ListNode* p = head;
    ListNode* c = p->next;
    ListNode* n = c->next;
    
    head = head->next;
    
    while(n && n->next)
    {
        c->next = p;
        p->next = n->next;
        
        p = n;
        c = p->next;
        n = c->next;
    }
    
    // remaining nodes
    c->next = p;
    p->next = n;
    
    return head;
}