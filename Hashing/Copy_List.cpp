/**
 * Definition for singly-linked list.
 * struct RandomListNode {
 *     int label;
 *     RandomListNode *next, *random;
 *     RandomListNode(int x) : label(x), next(NULL), random(NULL) {}
 * };
 */
RandomListNode* Solution::copyRandomList(RandomListNode* head)
{
    // map addresses of ols and new list
    unordered_map<RandomListNode*, RandomListNode*> M;
    
    // dummy head for new list
    RandomListNode* newHead = new RandomListNode(0);
    RandomListNode* nh = newHead;
    RandomListNode* h = head;
    
    while(h)
    {
        RandomListNode* temp = new RandomListNode(h->label);
        nh->next = temp;
        
        M[h] = temp;
        
        nh = nh->next;
        h = h->next;
    }
    
    // to make the random links
    h = head;
    nh = newHead->next;
    
    while(h)   
    {
        if(h->random != NULL)
            nh->random = M[h->random];
        
        h = h->next;
        nh = nh->next;
    }
    
    return newHead->next;
}