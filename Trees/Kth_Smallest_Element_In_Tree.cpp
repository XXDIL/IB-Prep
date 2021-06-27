/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

void traverse(TreeNode* root, vector<int>& nums)
{
    if(!root) return;
    
    traverse(root->left, nums);
    nums.push_back(root->val);
    traverse(root->right, nums);
}

/* inorder */
int Solution::kthsmallest(TreeNode* root, int k)
{
    vector<int> nums;
    traverse(root, nums);
    
    return nums[k-1];
}