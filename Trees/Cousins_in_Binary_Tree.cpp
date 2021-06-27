/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

/* altough this is an easy question there are a lot of cancer cases */
vector<int> Solution::solve(TreeNode* root, int x)
{
    queue<TreeNode*> frontier;
    frontier.push(root);
    
    int n = 1;
    bool found = 0;
            
    while(!frontier.empty())
    {   
        for(int i=0;i<n;++i)
        {
            auto front = frontier.front();
            frontier.pop();
            
            if(front->left)
            {
                if(front->left->val == x)
                {
                    found = 1;
                    if(front->right) continue;
                }
                else if(front->right && front->right->val == x)
                {
                    found = 1;
                    continue;
                }
                else
                    frontier.push(front->left);
            }
            if(front->right)
            {
                if(front->right->val == x)
                {
                    found = 1;
                    continue;
                }
                else
                    frontier.push(front->right);
            }
        }
        
        if(found) // the queue contains the cousins of x
        {
            vector<int> ans;
            while(!frontier.empty())
            {
                ans.push_back(frontier.front()->val);
                frontier.pop();
            }
            return ans;
        }
        
        n = frontier.size();
    }
    
    return {};
}