/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */

/*
    The logic is to maintain a gap of n nodes.
    Then move temp_head and the delay pointer at the same time
*/

ListNode* Solution::removeNthFromEnd(ListNode* head, int n)
{
    // setting a delay of n nodes
    ListNode* d = head;
    while(d && n--)
        d = d->next;
                    
    // n > list size
    if(n >= 0)
        return head->next;
    
    // move h to just b4 the node to be deleted
    ListNode* h = head;
    while(d->next)
    {
        h = h->next;
        d = d->next;
    }
    
    // skip the node
    h->next = h->next->next;
    
    return head;
}