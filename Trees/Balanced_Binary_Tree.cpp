/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

/* find the height of left and right sub trees and if the diff is > 1 make ans = 0 */
bool ans;
int help(TreeNode* root)
{
    if(!root) return 0;
    
    int l = help(root->left);
    int r = help(root->right);
    
    if(abs(l-r) > 1) ans = 0;
    
    return max(l, r) + 1;
}
        
int Solution::isBalanced(TreeNode* root)
{
    ans = 1;
    help(root);

    return ans;
}