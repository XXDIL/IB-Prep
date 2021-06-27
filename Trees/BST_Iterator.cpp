/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

/* store all the left nodes in stack */

stack<TreeNode*> S;

BSTIterator::BSTIterator(TreeNode *root) 
{
    while(root)
    {
        S.push(root);
        root = root->left;
    }
}

bool BSTIterator::hasNext()
{
    return !S.empty();
}

int BSTIterator::next() 
{
    auto nxt = S.top();
    S.pop();
    
    if(nxt->right)
    {
        TreeNode* ptr = nxt->right;
        while(ptr)
        {
            S.push(ptr);
            ptr = ptr->left;
        }
    }
    
    return nxt->val;
}

/**
 * Your BSTIterator will be called like this:
 * BSTIterator i = BSTIterator(root);
 * while (i.hasNext()) cout << i.next();
 */