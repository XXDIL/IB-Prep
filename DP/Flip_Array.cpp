/* 
    the main concept is subset sum, and an extention of equal sum partition

    if we are flipping the signs and then taking sum its basically
        a + b - c -d + e OR (a + b + d) - (c + d)

    so split the array into 2 subsets with min difference
        S1 - S2 = diff (minimize diff)
        S1 + S2 = sum

    therefore S1 = (sum + diff)/2    <-  now decide a range for diff
        diff => [0, sum]

    so if we call subsetSum(A, n, sum) the last row of the DP table
    will contain all the possible diff given the whole array.

    rest is trivial
*/
int Solution::solve(const vector<int> &A)
{
    int S = accumulate(A.begin(), A.end(), 0);
    int n = A.size();

    vector<vector<pair<bool, int>>> dp(n+1, vector<pair<bool, int>>(S+1, {0,0}));
    for(int i=0;i<=n;++i) dp[i][0] = {1, 0};

    // whenever u go to top right we add 1 to the lengts(obvious)
    for(int i=1;i<=n;++i)
    {
        for(int j=1;j<=S;++j)
        {
            if(j-A[i-1] >= 0)
            {                
                if(dp[i-1][j].first && dp[i-1][j-A[i-1]].first)
                    dp[i][j] = {1, max(dp[i-1][j].second, dp[i-1][j-A[i-1]].second + 1)};
                else if(dp[i-1][j].first)
                    dp[i][j] = dp[i-1][j];
                else if(dp[i-1][j-A[i-1]].first)
                    dp[i][j] = {1, dp[i-1][j-A[i-1]].second+1};
            }
            else
                dp[i][j] = dp[i-1][j];
        }
    }
    
    int ans = -1, val = INT_MAX;
    int start = S/2 + (S&1); // odd and even sums are different
    
    for(int i=start;i<=S;++i)
    {
        if(dp[n][i].first && 2*i-S < val)
        {            
            val = 2*i-S;
            ans = dp[n][i].second;
        }
    }
    
    return n-ans;
}