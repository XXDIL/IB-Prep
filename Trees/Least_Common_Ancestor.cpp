/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
/* using I/P method */
void help(TreeNode* root, int p, int q, vector<int>& temp, vector<int>& A, vector<int>& B)
{
    if(!root) return;
    
    temp.push_back(root->val);
    
    if(root->val == p) A = temp;
    if(root->val == q) B = temp;
    
    help(root->left, p, q, temp, A, B);
    help(root->right, p, q, temp, A, B);
    
    temp.pop_back();
}

/* just make sure you take care of the case when i = 0 */
int Solution::lca(TreeNode* root, int p, int q)
{
    vector<int> temp, A, B;
    help(root, p, q, temp, A, B);

    int i = 0;
    while(i<A.size() && i<B.size() && A[i] == B[i])
        i++;
    
    return (i == 0) ? -1 : A[i-1];
}