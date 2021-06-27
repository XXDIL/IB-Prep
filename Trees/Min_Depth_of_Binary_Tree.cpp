/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
int Solution::minDepth(TreeNode* root)
{
    if(root == NULL)
        return 0;

    int l = minDepth(root->left);
    int r = minDepth(root->right);

    // if the minimum is 0 then its a leaf node so we take max for that node
    return min(l, r) ? min(l, r)+1 : max(l, r)+1;
}