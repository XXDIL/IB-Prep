/*
    after a little analysis we can see that the question is actually
        "how many occurances of B are in A"

    Base cases :
        1) A = "" B = "A"      -> 0
        2) A = "ABC" B = ""    -> 1

    Note : make sure to keep B on the left and A on top (of DP table).
*/
int Solution::numDistinct(string A, string B)
{
    int m = A.size();
    int n = B.size();

    unsigned int dp[n+1][m+1];
    for(int i=0;i<=m;++i) dp[0][i] = 1;
    for(int i=1;i<=n;++i) dp[i][0] = 0;
    
    for(int i=1;i<=n;++i)
    {
        for(int j=1;j<=m;++j)
        {
            if(A[j-1] == B[i-1])
                dp[i][j] = dp[i][j-1] + dp[i-1][j-1]; // #occ of B[j] + #occ of B[:j] so far in A[:j]
            else
                dp[i][j] = dp[i][j-1]; // just the left val
        }
    }
    
    return dp[n][m];
}