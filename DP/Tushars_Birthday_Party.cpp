/* 
    use 0/1 unbounded knapsack logic to build the DP table.
    the last row is the main row and just take the sum of dp[n][A[i]].
*/
int Solution::solve(const vector<int> &A, const vector<int> &B, const vector<int> &C)
{  
    int n = B.size();
    int S = *max_element(A.begin(), A.end());
    
    vector<vector<int>> dp(n+1, vector<int>(S+1, 0));
    for(int i=1;i<=S;++i) dp[0][i] = 1000000007;
    
    for(int i=1;i<=n;++i)
    {
        for(int j=1;j<=S;++j)
        {
            if(j-B[i-1]>=0)
            {
                int l = dp[i-1][j];
                int r = dp[i][j-B[i-1]] + C[i-1];

                dp[i][j] = min(l, r);
            }
            else
                dp[i][j] = dp[i-1][j];
        }
    }
    
    int ans = 0;
    for(auto i : A)
        ans += dp[n][i];
    
    return ans;
}