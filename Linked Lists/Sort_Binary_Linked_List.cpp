/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
ListNode* Solution::solve(ListNode* head)
{
    ListNode* p = head;
    int z = 0;
    
    // count the number of 0's
    while(p)
    {
        if(p->val == 0) z++;
        
        p = p->next;
    }
    
    // place 0's from the start
    p = head;
    while(z!=0)
    {
        p->val = 0;
        p = p->next;
        z--;
    }
    
    // place 1's from end of 0's till null
    while(p)
    {
        p->val = 1;
        p = p->next;
    }
    
    return head;
}