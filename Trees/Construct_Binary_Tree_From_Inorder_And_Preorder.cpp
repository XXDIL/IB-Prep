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
    basically bin search but instead of calculating the 
    mid index we use inorder map to decide the index. 
*/
TreeNode* help(vector<int>& pre, int& prei, int l, int r, unordered_map<int, int>& M)
{
    if(l > r) return NULL;
    
    int val = pre[prei];
    TreeNode* root = new TreeNode(val);
    prei++;
            
    root->left = help(pre, prei, l, M[val]-1, M);
    root->right = help(pre, prei, M[val]+1, r, M);
            
    return root;
}

TreeNode* Solution::buildTree(vector<int> &preorder, vector<int> &inorder)
{
    int prei = 0;
    unordered_map<int, int> M;
    for(int i=0;i<inorder.size();++i)
        M[inorder[i]] = i;
    
    return help(preorder, prei, 0, preorder.size()-1, M);
}