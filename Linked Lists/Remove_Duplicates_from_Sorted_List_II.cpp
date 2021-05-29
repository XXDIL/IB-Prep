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

    // creating a dummy head
    ListNode* p = new ListNode(0);
    p->next = head;
    head = p;        
    ListNode* c = head->next;
    
    // normal c->val == c->next->val, comparision
    while(c && c->next)
    {
        while(c->next && c->val == c->next->val)
            c = c->next;
        
        if(p->next != c)    // Deletion 
            p->next = c->next;
        else                // No Deletion
            p = c;
        
        c = c->next;
    }

    return head->next;
}