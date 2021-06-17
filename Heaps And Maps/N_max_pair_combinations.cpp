/* Repeated Question : Maximum_Sum_Combinations.cpp */
vector<int> Solution::solve(vector<int>& A, vector<int>& B)
{
    sort(A.begin(), A.end());
    sort(B.begin(), B.end());

    int n = A.size();
    int C = n;

    set<pair<int, int>> S;
    priority_queue<vector<int>> maxh;
    maxh.push({A[n-1]+B[n-1], n-1, n-1});

    vector<int> ans;
    while(C--)
    {
        auto top = maxh.top();

        ans.push_back(top[0]);

        maxh.pop();

        if(top[1]-1 >= 0 && S.find({top[1]-1, top[2]}) == S.end())
        {
            maxh.push({A[top[1]-1]+B[top[2]], top[1]-1, top[2]});
            S.insert({top[1]-1, top[2]});
        }
        
        if(top[2]-1 >= 0 && S.find({top[1], top[2]-1}) == S.end())
        {
            maxh.push({A[top[1]]+B[top[2]-1], top[1], top[2]-1});
            S.insert({top[1], top[2]-1});
        }
    }

    return ans;

}