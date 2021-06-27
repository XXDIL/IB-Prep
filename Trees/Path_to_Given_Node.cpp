/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

/* if we find the value then push the temp vector and stop the process */
void help(TreeNode* root, int T, vector<int>& temp, vector<int>& ans)
{
    if(root == NULL) return;

    temp.push_back(root->val);

    if(root->val == T)
    {
        ans = temp;
        return;
    }

    help(root->left, T, temp, ans);
    help(root->right, T, temp, ans);

    temp.pop_back();
}

vector<int> Solution::solve(TreeNode* root, int T)
{
    vector<int> ans;
    vector<int> temp;
    
    help(root, T, temp, ans);

    return ans;
}