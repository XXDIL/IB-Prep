/*
    Recursive solution:

        bool help(vector<int>& A, int B, int n)
        {
            if(n == 0)
                return (B == 0) ? 1 : 0;

            bool l = help(A, B, n-1);
            bool r = 0;
            if(B-A[n-1] >= 0)
                r = help(A, B-A[n-1], n-1);
            
            return l|r;
        }
*/


/* 
    Recursive DP solution:

        vector<vector<int>> dp;
        bool help(vector<int>& A, int B, int n)
        {
            if(n == 0)
                return (B == 0) ? 1 : 0;

            if(dp[n][B] != -1)
                return dp[n][B];

            if(B-A[n-1] >= 0)
                dp[n][B] = help(A, B, n-1) | help(A, B-A[n-1], n-1);
            else
                dp[n][B] = help(A, B, n-1);
            
            return dp[n][B];
        }

        int Solution::solve(vector<int> &A, int B)
        {
            int n = A.size();
            dp = vector<vector<int>>(n+1, vector<int>(B+1, -1));

            return help(A, B, n);
        }
*/


/* Iterative DP (Tabulation) */
int Solution::solve(vector<int> &A, int B)
{
    int n = A.size();
    vector<vector<bool>>dp(n+1, vector<bool>(B+1));
    for(int i=0;i<=n;++i)
        dp[0][i] = 1;

    for(int i=1;i<=n;++i)
    {
        for(int j=1;j<=B;++j)
        {
            if(j-A[i-1] >= 0)
                dp[i][j] = dp[i-1][j] | dp[i-1][j-A[i-1]];
            else
                dp[i][j] = dp[i-1][j];
        }
    }

    return dp[n][B];
}