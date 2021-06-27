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
    use morris inorder traversal and replace 

        cout << cutt->val << " ";

    with 

        if(prev->val > curr->val)
        {
            if(f == NULL) 
                f = prev;
            
            s = curr;
        }
        prev = curr;


    the logic is that the inorder traversal of a BS should be sorted.
    so if the prev val is greater than the curr val the prev val is the val to be swapped

    corner case : if the elements to be swapped are next to each other
*/
vector<int> Solution::recoverTree(TreeNode* root)
{  
    TreeNode* f = NULL;
    TreeNode* s = NULL;
    TreeNode* prev = new TreeNode(INT_MIN);
    TreeNode* curr = root;

    while(curr)
    {
        if(!curr->left)
        {
            if(prev->val > curr->val)
            {
                if(f == NULL) 
                    f = prev;

                s = curr;
            }
            prev = curr;
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
                if(prev->val > curr->val)
                {
                    if(f == NULL) 
                        f = prev;
                    
                    s = curr;
                }
                prev = curr;
                curr = curr->right;
            }
        }
    }

    vector<int> ans = {min(f->val, s->val), max(f->val, s->val)};
    return ans;
}