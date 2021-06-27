/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

/* Level order traverse */
int Solution::solve(TreeNode* root)
{
    queue<TreeNode*> frontier;
    frontier.push(root);
    
    int ans = INT_MIN;
    int n = 1;
    
    while(!frontier.empty())
    {
        int levelSum = 0;
        for(int i=0;i<n;++i)
        {
            auto front = frontier.front();
            frontier.pop();
            
            levelSum += front->val;
            
            if(front->left) frontier.push(front->left);
            if(front->right) frontier.push(front->right);
        }
        
        ans = max(ans, levelSum);
        n = frontier.size();
    }
    
    return ans;
}