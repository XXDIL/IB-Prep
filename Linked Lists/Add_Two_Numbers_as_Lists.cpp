/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
ListNode* Solution::addTwoNumbers(ListNode* A, ListNode* B)
{
    ListNode* tA = A;
    ListNode* tB = B;
    int carry = 0;
    
    while(tA && tB)
    {
        int sum = tA->val + tB->val + carry;
        
        tA->val = sum%10;
        carry = sum/10;
        
        tA = tA->next;
        tB = tB->next;
    }
    
    // A : [9, 9] & B : [9, 9, 9, 9]
    ListNode* prev_tA; // make it faster to get the last node
    if(tB != NULL && tA == NULL)
    {
        ListNode* t2A = A;
        while(t2A->next)
            t2A = t2A->next;
        prev_tA = t2A;
        
        t2A->next = tB;
        tA = t2A->next;
    }
            
    // now we can take care of the carry 1 case for uneven length lists
    while(carry && tA)
    {            
        int sum = tA->val + carry;
        tA->val = sum%10;
        
        carry = sum/10;
        tA = tA->next;
    }
    
    // final carry addition of a new node.
    if(carry)
    {
        ListNode* prev_tA = A;
        while(prev_tA->next)
            prev_tA = prev_tA->next;
        
        ListNode* temp = new ListNode(1);
        prev_tA->next = temp;
    }
    
    return A;
}