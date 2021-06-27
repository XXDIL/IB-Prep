/**
 * Definition for binary tree with next pointer.
 * struct TreeLinkNode {
 *  int val;
 *  TreeLinkNode *left, *right, *next;
 *  TreeLinkNode(int x) : val(x), left(NULL), right(NULL), next(NULL) {}
 * };
 */

/* not as hard as it seems, simple level order */
void Solution::connect(TreeLinkNode* root)
{
    if(!root) return;
    
    queue<TreeLinkNode*> frontier;
    frontier.push(root);

    int n = 1;

    while(!frontier.empty())
    {
        for(int i=0;i<n;++i)
        {
            auto front = frontier.front();
            frontier.pop();

            if(front->left)
                frontier.push(front->left);

            if(front->right)
                frontier.push(front->right);
            
            if(i == n-1)
                front->next = NULL;
            else
                front->next = frontier.front();
        }

        n = frontier.size();
    }
}