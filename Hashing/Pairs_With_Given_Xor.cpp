/* literally the same logic as 2sum and 2diff */
int Solution::solve(vector<int>& A, int B)
{
    int n = A.size();
    unordered_map<int, int> M;
    int ans = 0;
    for(int i=0;i<n;++i)
    {
        if(M.find(A[i]) == M.end())
        {
            if(M.find(B^A[i]) == M.end())
                M[B^A[i]] = i;
        }

        else ans++;
    }

    return ans;
}