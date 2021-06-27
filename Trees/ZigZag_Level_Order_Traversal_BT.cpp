/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

/* just use a bool to decide when to reverse */
vector<vector<int> > Solution::zigzagLevelOrder(TreeNode* root)
{
    if(!root) return {};
    
    queue<TreeNode*> frontier;
    frontier.push(root);
    
    vector<vector<int>> ans;
    int n = 1;
    bool rev = 0;
    
    while(!frontier.empty())
    {
        vector<int> level;
        for(int i =0;i<n;++i)
        {
            auto front = frontier.front();
            frontier.pop();
            
            if(front->left) frontier.push(front->left);
            if(front->right) frontier.push(front->right);
            
            level.push_back(front->val);
        }
        
        if(rev)
            reverse(level.begin(), level.end());
        
        ans.push_back(level);
        n = frontier.size();
        rev = 1 - rev;
    }
    
    return ans;
}