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
    go to the bottom and start deleting nodes from there.

    deletion is easy because its like deletion in a linked list.
    (only one child)
*/
TreeNode* Solution::solve(TreeNode* root)
{
    if(!root || (!root->left && !root->right)) return root;

    root->left = solve(root->left);
    root->right = solve(root->right);

    if(!root->left) return root->right;
    if(!root->right) return root->left;

    return root;
}