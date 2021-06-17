/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */

/*
    too easy. just make sure to maintain a PQ of (val, headptrs)
*/
ListNode* Solution::mergeKLists(vector<ListNode*>& lists)
{
    priority_queue<pair<int, ListNode*>, vector<pair<int, ListNode*>>, greater<pair<int, ListNode*>>> minh;
    vector<ListNode*> ptrs;
    
    for(auto list : lists)
    {
        if(list == NULL) continue;
        
        ptrs.push_back(list);
        minh.push({list->val, list});
    }
    
    ListNode* ans = new ListNode(0);
    ListNode* ansptr = ans;
    while(!minh.empty())
    {
        auto top = minh.top();
        
        minh.pop();
        
        ListNode* node = new ListNode(top.first);
        ansptr->next = node;
        ansptr = ansptr->next;
        
        if(top.second->next)
            minh.push({top.second->next->val, top.second->next});
    }
    
    return ans->next;
}