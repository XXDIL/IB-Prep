/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

/* think in terms of binary search */
TreeNode* help(int l, int r, vector<int>& nums)
{
    if(l > r) return NULL;
    
    int m = l + (r-l)/2;
    
    TreeNode* root = new TreeNode(nums[m]);
    
    root->left = help(l, m-1, nums);
    root->right = help(m+1, r, nums);
    
    return root;
}

TreeNode* Solution::sortedArrayToBST(const vector<int>& nums)
{
    vector<int> temp(nums.begin(), nums.end());
    return help(0, temp.size()-1, temp);
}