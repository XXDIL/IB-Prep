/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
ListNode* Solution::mergeTwoLists(ListNode* A, ListNode* B)
{
    /* Tipical 12th grade logic */
    ListNode* C = new ListNode(0);
    ListNode* tc = C;
    
    while(A && B)
    {
        if(A->val < B->val)
        {
            ListNode* temp = new ListNode(A->val);
            tc->next = temp;
            A = A->next;
        }
        else
        {
            ListNode* temp = new ListNode(B->val);
            tc->next = temp;
            B = B->next;
        }
        
        tc = tc->next;
    }
    
    if(!A) // B has more elements
        tc->next = B;
    
    if(!B) // A has more elements
        tc->next = A;
    
    return C->next;
}