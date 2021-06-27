struct TrieNode
{
    map<char, TrieNode*> children;
    int count;
};

/* simple TRIE insert */
void insert(TrieNode* root, string s)
{
    TrieNode* ptr = root;
    for(auto i : s)
    {
        if(!ptr->children[i])
        {
            TrieNode* node = new TrieNode();
            ptr->children[i] = node;
        }

        ptr->count++;
        ptr = ptr->children[i];
    }
}

/* exploring the tree till we encounter count = 1 (root count = 0) */
string trace(TrieNode* root, string& T)
{
    TrieNode* ptr = root;
    int n = T.size();
    int i = 0;
    while(i < n && ptr->count != 1)
        ptr = ptr->children[T[i++]];

    return T.substr(0, i);
}

vector<string> Solution::prefix(vector<string> &A)
{
    TrieNode* root = new TrieNode();
    for(auto a : A)
        insert(root, a);

    vector<string> ans;
    for(auto& a : A)
        ans.push_back(trace(root, a));

    return ans;
}