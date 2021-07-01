/* 
    Think in the lines of -> left2right and right2left arrays

    add 1 if the next value is greater else let it be 1

    take max of l2r and r2l, then sum
*/
int Solution::candy(vector<int> &A)
{
    int n = A.size();

    vector<int> dp(n, 1);
    for(int i=1;i<n;++i)
    {
        if(A[i] > A[i-1])
            dp[i] = dp[i-1] + 1;
    }

    int ans = dp[n-1];
    for(int i=n-2;i>=0;--i)
    {
        int prev_dp_i = dp[i];
        if(A[i] > A[i+1])
            dp[i] = dp[i+1] + 1;

        ans += max(dp[i], prev_dp_i);
    }

    return ans;
}