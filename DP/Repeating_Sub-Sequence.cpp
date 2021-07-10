/* LCS wit a simple if condition modification */
int Solution::anytwo(string A)
{
    int n = A.size();
    int dp[n+1][n+1];
    for(int i=0;i<=n;++i) dp[i][0] = 0;
    for(int i=1;i<=n;++i) dp[0][i] = 0;

    for(int i=1;i<=n;++i)
    {
        for(int j=1;j<=n;++j)
        {
            if(i!=j && A[i-1] == A[j-1]) // i!=j to avoid same index character
                dp[i][j] = 1+dp[i-1][j-1];
            else
                dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
        }
    }
    
    return dp[n][n] >= 2 ? 1 : 0; // constraint was : a subsequence min len = 2
}