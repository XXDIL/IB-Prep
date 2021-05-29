/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
ListNode* Solution::deleteDuplicates(ListNode* head)
{
    // corner cases
    if(head == NULL || head->next == NULL)
        return head;
    
    // simple logic
    ListNode* a = head;
    ListNode* b = head->next;
    while(a)
    {
        while(b && a->val == b->val)
            b = b->next;
        
        a->next = b;
        a = b;
    }
    
    return head;
}