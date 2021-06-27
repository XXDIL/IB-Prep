/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

/* normal search in BST, O(height) : super fast */
bool searchPair(TreeNode* root, int ele)
{
    TreeNode* ptr = root;
    while(ptr)
    {
        if(ptr->val == ele)
            return 1;
        
        if(ptr->val > ele)
            ptr = ptr->left;
        else
            ptr = ptr->right;
    }
    
    return 0;
}

/* 
    visit all nodes and find their corresponding 2-sum pairs.

    if pair exists(m = 1) then return 1
    else keep searching left and right

    there is just 1 corner case BST:[2,1] k = 2 (basically no repeated values)
 */
bool help(TreeNode* root, TreeNode* ptr, int k)
{
    if(!ptr) return 0;
    
    bool m;
    if(k-ptr->val == ptr->val) m = 0; // to tackle repeated pairs
    else m = searchPair(root, k-ptr->val);
    
    if(m) return 1;
    
    return help(root, ptr->left, k) | help(root, ptr->right, k);
}

int Solution::t2Sum(TreeNode* root, int k)
{
    return help(root, root, k);
}