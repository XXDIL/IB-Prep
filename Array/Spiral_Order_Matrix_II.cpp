/* just cancerous indexing */
vector<vector<int>> Solution::generateMatrix(int n)
{
    vector<vector<int>> M(n, vector<int>(n));
    
    int val = 1;
    int a = 0;
    while(a <= n/2)
    {
        int s=a, e=n-1-a;
        for(int i=s;i<=e;++i)
            M[s][i] = val++;
        for(int i=s+1;i<=e;++i)
            M[i][e] = val++;

        for(int i=e-1;i>=s;--i)
            M[e][i] = val++;
        for(int i=e-1;i>=s+1;--i)
            M[i][s] = val++;
        
        a++;
    }
    
    return M;
}