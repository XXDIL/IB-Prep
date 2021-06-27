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
    similar to Construct_Binary_Tree_From_Inorder_And_Preorder.cpp mainly change 2 things:

    1) call right then left and swap the RHS of those 2 statements
    2) start i pointer from the end (instead of from the start)

 */
TreeNode* help(vector<int>& post, int& posti, int l, int r, unordered_map<int, int>& M)
{
    if(l > r) return NULL;
    
    int val = post[posti];
    TreeNode* root = new TreeNode(val);
    posti--;
    
    root->right = help(post, posti, M[val]+1, r, M);
    root->left = help(post, posti, l, M[val]-1, M);
    
    return root;
}

TreeNode* Solution::buildTree(vector<int> &inorder, vector<int> &postorder)
{
    int n = inorder.size();
    int posti = n-1;
    
    unordered_map<int, int> M;
    for(int i=0;i<n;++i)
        M[inorder[i]] = i;
    
    return help(postorder, posti, 0, n-1, M);
}