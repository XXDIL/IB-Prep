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
    make the trees like this.

              1
           2     3
          4 5   6 7   

          1
        2   3
         4   6
          5   7

    then its basic Linked List logic    
*/
TreeNode* Solution::flatten(TreeNode* root)
{
    if(!root) return root;
    
    root->left = flatten(root->left);
    root->right = flatten(root->right);
    
    TreeNode* rptr = root->left;
    while(rptr && rptr->right)
        rptr = rptr->right;
    
    if(rptr)
        rptr->right = root->right;
    if(root->left)
        root->right = root->left;
    
    root->left = NULL;

    return root;
}