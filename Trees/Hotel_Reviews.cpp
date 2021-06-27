struct TrieNode
{
    vector<TrieNode*> children;
    int count;

    TrieNode()
    {
        children = vector<TrieNode*>(26, NULL);
        count = 0;
    }
};

// tipical
void insert(TrieNode* root, string s)
{
    TrieNode* ptr = root;
    for(auto i : s)
    {
        if(!ptr->children[i-'a'])
        {
            TrieNode* node = new TrieNode();
            ptr->children[i-'a'] = node;
        }
        
        ptr = ptr->children[i-'a'];
    }
    ptr->count = 1;
}

// pretty much the same bs
int trace(TrieNode* root, string T)
{
    TrieNode* ptr = root;
    int n = T.size();

    int i = 0;
    while(i < n && ptr->children[T[i] - 'a'])
        ptr = ptr->children[T[i++] - 'a'];

    return (i == n) ? ptr->count : 0;
}

static bool mycomp(pair<int, int> a, pair<int, int> b)
{
    return (a.first>b.first) || (a.first==b.first && a.second<b.second);
}

/* looks more complicated that it actually is */
vector<int> Solution::solve(string A, vector<string> &B)
{
    TrieNode* root = new TrieNode();
    
    // putting A into TRIE
    int i=0, j=0;
    while(i < A.size())
    {
        while(j < A.size() && A[j] != '_') j++;

        insert(root, A.substr(i, j-i));

        i = j+1;
        j++;
    }

    // searching for every word in B[i] and finding the good value
    vector<pair<int, int>> M;
    for(int a=0;a<B.size();++a)
    {
        int i=0, j=0;
        int goodValue = 0;
        while(i < B[a].size())
        {
            while(j < B[a].size() && B[a][j] != '_') j++;

            goodValue += trace(root, B[a].substr(i, j-i));

            i = j+1;
            j++;
        }

        M.push_back({goodValue, a});
    }
    
    // custom comparator to match the requirements
    sort(M.begin(), M.end(), mycomp);
    
    vector<int> ans;
    for(auto i : M)
        ans.push_back(i.second);

    return ans;
}