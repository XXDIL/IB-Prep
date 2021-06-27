/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

/* in level order traversal just push the last element of each level into ans */
vector<int> Solution::solve(TreeNode* root)
{
    if(!root) return {};
    
    queue<TreeNode*> frontier;
    frontier.push(root);
    
    vector<int> ans;
    int n = 1;
    
    while(!frontier.empty())
    {
        for(int i=0;i<n;++i)
        {
            auto front = frontier.front();
            frontier.pop();
            
            if(front->left) frontier.push(front->left);
            if(front->right) frontier.push(front->right);
            
            if(i == n-1)
                ans.push_back(front->val);
        }
        
        n = frontier.size();
    }
    
    return ans;
}