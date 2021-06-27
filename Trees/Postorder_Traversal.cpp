/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

/*
    this is called reverse insert. The idea is to 
    retrieve the ans array in reverse
*/
vector<int> Solution::postorderTraversal(TreeNode* root)
{
    stack<TreeNode*> S;
    if(root)
        S.push(root);

    vector<int> ans;
    
    while(!S.empty())
    {
        auto top = S.top();
        S.pop();
        
        ans.push_back(top->val);
        
        if(top->left) 
            S.push(top->left);
        if(top->right) 
            S.push(top->right);
    }

    reverse(ans.begin(), ans.end());

    return ans;
}