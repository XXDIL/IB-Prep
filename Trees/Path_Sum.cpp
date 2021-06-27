/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
/* trivial */
bool leafsum(TreeNode* root, int sum, int T)
{
    if(root == NULL) return 0;
    
    if(sum+root->val == T && root->left == NULL && root->right == NULL)
        return 1;
    
    bool l = leafsum(root->left, sum + root->val, T);
    
    if(l == 1) return 1;
    return leafsum(root->right, sum + root->val, T);
}

int Solution::hasPathSum(TreeNode* A, int B)
{
    return leafsum(A, 0, B);
}