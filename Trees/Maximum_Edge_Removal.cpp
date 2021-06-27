int ans;

/* use DFS traversal to calculate the count of nodes for every subtree */
int countNodes(int root, unordered_map<int, vector<int>>& tree)
{    
    int rootSum = 1;
    for(int i : tree[root])
    {
        int subCount = countNodes(i, tree);

        if(subCount % 2 == 0)
            ans++;

        rootSum += subCount;
    }

    return rootSum;
}
/* 1 is the root always */
int Solution::solve(int A, vector<vector<int>>& B)
{
    // making the tree
    unordered_map<int, vector<int>> tree;
    for(auto i : B)
        tree[i[0]].push_back(i[1]);

    ans = 0;
    countNodes(1, tree);

    return ans;
}