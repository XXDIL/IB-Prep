/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
int Solution::maxDepth(TreeNode* root)
{
    if(root == NULL)
        return 0;

    int l = maxDepth(root->left);
    int r = maxDepth(root->right);

    return max(l, r) + 1;
}