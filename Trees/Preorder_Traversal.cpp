/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

/* one observation is to store only the right nodes */
vector<int> Solution::preorderTraversal(TreeNode* root)
{
    stack<TreeNode*> S;
    vector<int> ans;
    
    while(root)
    {            
        ans.push_back(root->val);
        
        if(root->right != NULL)
            S.push(root->right);
        
        root = root->left;
        
        if(root == NULL && !S.empty())
        {
            root = S.top();
            S.pop();
        }
    }
    
    return ans;
}