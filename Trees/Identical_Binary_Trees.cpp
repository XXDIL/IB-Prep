/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

/* left subtree, right subtree as well as the root value should be same */
int Solution::isSameTree(TreeNode* p, TreeNode* q)
{
    if(p == NULL && q == NULL) return 1;
    if(p == NULL || q == NULL) return 0;
    
    return (p->val == q->val && isSameTree(p->left, q->left) && isSameTree(p->right, q->right));
}