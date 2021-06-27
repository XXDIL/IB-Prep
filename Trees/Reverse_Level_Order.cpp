/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

/* simple level order traversal, with a little manipulation */
vector<int> Solution::solve(TreeNode* root)
{
    if(!root) return {};
    
    queue<TreeNode*> frontier;
    frontier.push(root);

    vector<int> ans;        
    int n = 1;

    while(!frontier.empty())
    {
        vector<int> level;
        for(int i=0;i<n;++i)
        {
            auto front = frontier.front();
            frontier.pop();

            level.push_back(front->val);

            if(front->left)
                frontier.push(front->left);

            if(front->right)
                frontier.push(front->right);
        }

        ans.insert(ans.begin(), level.begin(), level.end()); // insert at the beginning of the vector
        n = frontier.size();
    }

    return ans;
}