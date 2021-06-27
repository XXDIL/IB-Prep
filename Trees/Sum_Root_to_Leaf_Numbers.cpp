/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

/* create the digits as you go deeper */
void help(TreeNode* root, int digit, int& sum)
{
    if(root == NULL) return;
    
    digit = (digit*10 + root->val)%1003;
    
    if(root->left == NULL && root->right == NULL)
    {
        sum = (sum+digit)%1003;
        return;
    }
    
    help(root->left, digit, sum);
    help(root->right, digit, sum);
}

int Solution::sumNumbers(TreeNode* root)
{
    int sum = 0;
    help(root, 0, sum);
    
    return sum%1003;
}