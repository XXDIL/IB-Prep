/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

/* keep pushing left nodes so later we can use them to visit the right nodes */
vector<int> Solution::inorderTraversal(TreeNode* root)
{
    stack<TreeNode*> S;
    vector<int> ans;    

    while(root || !S.empty())
    {
        while(root)
        {
            S.push(root);
            root = root->left;
        }
        
        ans.push_back(S.top()->val);
        root = S.top()->right;
        S.pop();
    }
    
    return ans;
}


/* Morris Inorder Traversal (easy) */
vector<int> inorderTraversal(TreeNode* root)
{
    vector<int> ans;
    TreeNode* curr = root;
    while(curr)
    {
        if(!curr->left)
        {
            ans.push_back(curr->val);
            curr = curr->right;
        }
        
        else
        {
            TreeNode* ptr = curr->left;
            while(ptr->right && ptr->right != curr)
                ptr = ptr->right;
            
            if(!ptr->right)
            {
                ptr->right = curr;
                curr = curr->left;
            }
            else
            {
                ptr->right = NULL;
                ans.push_back(curr->val);
                curr = curr->right;
            }
        }
    }
    
    return ans;
}