/* 
    Think Recursive first
    
    int help(vector<int>& val, vector<int>& wt, int W, int n)
    {
        if(n == 0 || W == 0)
            return 0;

        int l = help(val, wt, W, n-1);
        if(W-wt[n-1] >= 0)
            int r = help(val, wt, W-wt[n-1], n-1) + val[n-1];

        return max(l, r);
    }
*/

/* 
    Recursice DP
    
    whenever we use l or r just put it into the dp location 
*/
vector<vector<int>> dp;
int help(vector<int>& val, vector<int>& wt, int W, int n)
{
    if(n == 0 || W == 0)
        return 0;

    // if its already been explored just use it
    if(dp[n][W] != -1)
        return dp[n][W];

    dp[n][W] = help(val, wt, W, n-1);
    if(W-wt[n-1] >= 0)
        dp[n][W] = max(dp[n][W], help(val, wt, W-wt[n-1], n-1) + val[n-1]);

    return dp[n][W];
}

/* dp table will be of shape nxW becausethose are the 2 variables that are changing */
int Solution::solve(vector<int> &A, vector<int> &B, int C)
{
    dp = vector<vector<int>>(A.size()+1, vector<int>(C+1, -1));

    return help(A, B, C, A.size());
}


/* 
    IMP : base condition in the recursive code becomes the initialization step of iteratuve DP

    Easy change from recursive DP to Iterative DP(tabulate)
*/
int Solution::solve(vector<int> &A, vector<int> &B, int W)
{
    int n = A.size();
    vector<vector<int>> dp(n+1, vector<int>(W+1, 0)); // initialization

    for(int i=1;i<=n;++i)
    {
        for(int j=1;j<=W;++j)
        {
            dp[i][j] = dp[i-1][j];

            if(j-B[i-1] >= 0)
                dp[i][j] = max(dp[i][j], dp[i-1][j-B[i-1]] + A[i-1]);
        }
    }

    return dp[n][W];
}