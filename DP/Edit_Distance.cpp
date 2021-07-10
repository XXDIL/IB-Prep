/*
    for questions like this, try LCS but if it doesnt fit then make the DP table

    Initialization:
        A = "" B = "AB"   -> i
        A = "AB" B = ""   -> i
    
    Propagation:
        if the letters match we need not do anything
        else we take min(insert, delete, replace) + 1 -> ie min(top, left, top-left) + 1
*/
int Solution::minDistance(string A, string B)
{
    int m = A.size();
    int n = B.size();
    
    int dp[n+1][m+1];
    for(int i=0;i<=n;++i) dp[i][0] = i;
    for(int i=1;i<=m;++i) dp[0][i] = i;
    
    for(int i=1;i<=n;++i)
    {
        for(int j=1;j<=m;++j)
        {
            if(A[j-1] == B[i-1])
                dp[i][j] = dp[i-1][j-1];
            else
                dp[i][j] = min(dp[i-1][j-1], min(dp[i-1][j], dp[i][j-1])) + 1;
        }
    }
    
    return dp[n][m];
}