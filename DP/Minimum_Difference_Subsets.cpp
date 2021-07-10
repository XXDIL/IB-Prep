#include <bits/stdc++.h>

/* 
    just use 0/1 knapsack -> subset sum logic

    sum(S1) - sum(S2) = diff(minimize)
    sum(S1) + sum(S2) = S

    sum(S1) = (S + diff)/2         (i)
    diff = [0, S]

    so do a 0/1 knap sack DP code on A with W as S
    the last row will give u all the possible subsets that have a sum j.

    then take the minimum of 
        abs(2*j - S) <- (from i)
*/
int Solution::solve(vector<int> &A)
{
    int n = A.size();
    int S = accumulate(A.begin(), A.end(), 0);

    bool dp[n+1][S+1];
    for(int i=0;i<=n;++i) dp[i][0] = 1;
    for(int i=1;i<=S;++i) dp[0][i] = 0;

    for(int i=1;i<=n;++i)
    {
        for(int j=1;j<=S;++j)
        {
            if(j-A[i-1] >= 0)
                dp[i][j] = dp[i-1][j] | dp[i-1][j-A[i-1]];
            else
                dp[i][j] = dp[i-1][j];
        }
    }

    int ans = INT_MAX;
    for(int j=0;j<=S;++j)
        if(dp[n][j])
            ans = min(ans, abs(2*j - S));

    return ans;
}