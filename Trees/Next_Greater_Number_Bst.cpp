/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

/* Binary search : maintain a "next" pointer dont stop if the val == B */
TreeNode* Solution::getSuccessor(TreeNode* root, int B)
{
    TreeNode* next = NULL;
    TreeNode* ptr = root;
    while(ptr)
    {
        if(ptr->val > B)
        {
            next = ptr;
            ptr = ptr->left;
        }
        else
            ptr = ptr->right;
    }

    return next;
}