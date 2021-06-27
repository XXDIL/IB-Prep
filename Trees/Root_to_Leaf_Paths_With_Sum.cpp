/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

/* Classic root to leaf traversal */
void help(TreeNode* root, int sum, int T, vector<int>& temp, vector<vector<int>>& ans)
{
    if(root == NULL) return;
    
    temp.push_back(root->val);
    
    if(sum+root->val == T && root->left == NULL && root->right == NULL)
    {
        ans.push_back(temp);
        temp.pop_back();
        return;
    }
    
    help(root->left, sum+root->val, T, temp, ans);
    help(root->right, sum+root->val, T, temp, ans);
    
    temp.pop_back();
}
 
vector<vector<int> > Solution::pathSum(TreeNode* root, int T)
{
    vector<vector<int>> ans;
    vector<int> temp;
    help(root, 0, T, temp, ans);
    
    return ans;
}