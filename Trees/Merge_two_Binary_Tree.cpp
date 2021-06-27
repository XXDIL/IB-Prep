/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

/*  make root1 tree the primary tree,  */
TreeNode* Solution::solve(TreeNode* root1, TreeNode* root2)
{
    if(root2 == NULL) return root1;
    if(root1 == NULL) return root2;
    
    root1->val += root2->val;
    /*
        these 2 statements are really nice, because u will come to the 
        realization that we need to attach the parent of a node to the
        child and this is the only way. 
    */
    root1->left = solve(root1->left, root2->left);
    root1->right = solve(root1->right, root2->right);
    
    return root1;
}