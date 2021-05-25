int Solution::solve(vector<int> &A)
{
    int m = A[0], M = A[0];
    int n = A.size();
    
    for(int i=1;i<n;++i)
    {
        m = min(m, A[i]);
        M = max(M, A[i]);
    }
    
    return M+m;
}