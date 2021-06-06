/*
    find running max from left  (ML)
    find running max from right (MR)

    take min(ML[i], MR[i])  (MIN)

    finally -> MIN[i] - A[i]
*/

int Solution::trap(const vector<int>& A)
{
    int n = A.size();
    vector<int> dp(n);
    int Max = -1;
    
    // left max
    for(int i=0;i<n;++i)
    {
        Max = max(Max, A[i]);
        dp[i] = Max;
    }
    
    // right max
    Max = -1;
    for(int i=n-1;i>=0;--i)
    {
        Max = max(Max, A[i]);
        dp[i] = min(Max, dp[i]);
    }
    
    // difference
    int ans = 0;
    for(int i=0;i<n;++i)
        ans += dp[i]-A[i];
    
    return ans;
}