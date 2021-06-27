/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

/* Queue stores all the right values. */
vector<int> Solution::solve(TreeNode* root)
{
    TreeNode* ptr = root;
    vector<int> ans;
    queue<TreeNode*> Q;
    
    while(ptr)
    {
        Q.push(ptr);
        ptr = ptr->right;
    }
    
    int n = Q.size();
    
    while(!Q.empty())
    {
        for(int i=0;i<n;++i)
        {
            auto front = Q.front();
            Q.pop();
            
            ans.push_back(front->val);
        
            if(!front->left) continue;
            
            TreeNode* temp = front->left;
            while(temp)
            {
                Q.push(temp);
                temp = temp->right;
            }
        }
        
        n = Q.size();
    }
    
    return ans;
}