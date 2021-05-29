/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
int Solution::solve(ListNode* head, int B)
{
    ListNode* a = head;
    ListNode* b = head;
    int c = 0;
    
    // so we need to traverse only N/2 times
    while(b && b->next)
    {
        c++;
        a = a->next;
        b = b->next->next;
    }
    
    c = c - B;
    if(c < 0) 
        return -1;
    
    while(c--)
        head = head->next;
    
    return head->val;
}