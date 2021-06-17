/*
    Clever solution,

        1) sort both arrays (obvious)
        2) start from the end of A and B (max sum will be from the end)
        3) store (sum, i, j) in PQ.
        4) each time just push (A[i-1]+B[j], i-1, j) and (A[i]+B[j-1], i, j-1) 
        5) maintain a set, so all the indices are unique.
*/
vector<int> Solution::solve(vector<int> &A, vector<int> &B, int C)
{
    sort(A.begin(), A.end());
    sort(B.begin(), B.end());

    int n = A.size();

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