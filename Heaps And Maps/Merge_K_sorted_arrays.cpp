/*
    you will need to store {val, i, j} in PQ.

    OR you can start from back of each array
*/
vector<int> Solution::solve(vector<vector<int>>& A)
{
    priority_queue<vector<int>, vector<vector<int>>, greater<vector<int>>> minh;
    vector<int> ans;

    int n = A.size();
    for(int i=0;i<n;++i)
        minh.push({A[i][0], i, 0});

    while(!minh.empty())
    {
        auto top = minh.top();

        minh.pop();
        ans.push_back(top[0]);
        if(top[2]+1 < A[0].size())
            minh.push({A[top[1]][top[2]+1], top[1], top[2]+1});
    }

    return ans;
}