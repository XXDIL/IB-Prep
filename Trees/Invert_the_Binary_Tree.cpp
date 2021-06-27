/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

/* we need to swap the links not the values */
TreeNode* Solution::invertTree(TreeNode* root)
{
    if (!root) return root;
    
    invertTree(root->left);
    invertTree(root->right);
    
    std::swap(root->left, root->right);
    
    return root;
}