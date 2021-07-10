/*
    Pure Recursion:
    
        int help(int N)
        {
            if(N == 0)
                return 1;

            if(N >= 2)
                return help(N-1) + help(N-2);

            return help(N-1);
        }
        
    Recursive DP:
    
        int help(int N)
        {
            if(N == 0)
                return 1;

            if(dp[N] != -1)
                return dp[N];

            if(N >= 2)
                dp[N] = help(N-1) + help(N-2);

            else
                dp[N] = help(N-1);

            return dp[N];
        }

    Tabulation:
*/
int Solution::climbStairs(int n)
{
    int dp[n+1];
    dp[0] = 1;
    
    for(int i=1;i<=n;++i)
    {
        if(i >= 2)
            dp[i] = dp[i-1] + dp[i-2];

        else
            dp[i] = dp[i-1];
    }
    
    return dp[n];
}