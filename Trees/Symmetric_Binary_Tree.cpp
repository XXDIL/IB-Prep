/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

/* the left subtree is the mirror of the right subtree and vice versa. The value also should be same */ 
bool help(TreeNode* A, TreeNode* B)
{
    if(A == NULL && B == NULL) return 1;
    if(A == NULL || B == NULL) return 0;

    return A->val==B->val && help(A->left, B->right) && help(A->right, B->left);
}
    
int Solution::isSymmetric(TreeNode* root)
{
    return help(root, root);
}