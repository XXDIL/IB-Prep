/* this is a binary TRIE */
struct TrieNode
{
    TrieNode* left;
    TrieNode* right;
};

/* insert a node to the left if 0 else insert the the right */
void insert(TrieNode* root, int n)
{
    TrieNode* ptr = root;
    for(int i=31;i>=0;--i)
    {
        if(n&(1<<i))
        {
            if(!ptr->right)
            {
                TrieNode* node = new TrieNode();
                ptr->right = node;
            }

            ptr = ptr->right;
        }
        else
        {
            if(!ptr->left)
            {
                TrieNode* node = new TrieNode();
                ptr->left = node;
            }

            ptr = ptr->left;
        }
    }
}

/* 
    folllow the TRIE down 
        going left(0) if the ith bit of n is 1
        going right(1) if the ith bit of n is 0

    we go the opposite way to maximise the value of XOR
*/
int findXorPair(TrieNode* root, int n)
{
    TrieNode* ptr = root;
    int ans = 0;
    for(int i=31;i>=0;--i)
    {
        if(n&(1<<i))
        {
            if(!ptr->left)
            {
                ptr = ptr->right;
                ans += (1<<i);
            }
            else
                ptr = ptr->left;
        }
        else
        {
            if(!ptr->right)
                ptr = ptr->left;
            else
            {
                ptr = ptr->right;
                ans += (1<<i);
            }
        }
    }

    return ans;
}

/* insert A into the TRIE and search for the max XOR pair one by on for B[i] */
int Solution::solve(vector<int> &A, vector<int> &B)
{
    TrieNode* root = new TrieNode();

    for(int i : A)
        insert(root, i);

    int max_xor = 0;
    for(int i : B)
        max_xor = max(max_xor, findXorPair(root, i) ^ i);

    return max_xor;   
}