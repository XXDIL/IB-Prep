/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
 
/*
    1) place tail
    2) calc mod etc for k
    3) place ptr just b4 kth pos (0 index)
    4) ptr manipulation
*/

ListNode* Solution::rotateRight(ListNode* head, int k)
{
    // corner cases and just a speedup
    if(head == NULL || head->next == NULL) return head;
    
    int n = 0; // keep note of list size
    ListNode* tail = head;
    while(tail->next)
    {
        n++;
        tail = tail->next;
    }
    
    n++;
    k %= n;     // obvious
    k = n-1-k;  // think about it
    
    ListNode* temp = head;
    while(k--)
        temp = temp->next;
    
    tail->next = head;
    head = temp->next;
    temp->next = NULL;
            
    return head;
}