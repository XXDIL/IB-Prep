/* 
    the more readable form is a 2D DP table in which 
    we take the sum of dp[i-1][j] and dp[i][j-A[i-1]] if its possible 
    else we just use dp[i-1][j]

    to compress it into a 1D array, notice that we are only using 
    top(i-1th past value) and left(ith past value) so only 1D Dp is necessary
*/
int Solution::coinchange2(vector<int> &A, int W)
{
    int dp[W+1];
    dp[0] = 1;
    for(int i=1;i<=W;++i) dp[i] = 0;
    
    for(auto i : A)
        for(int j=i;j<=W;++j)
            dp[j] = (dp[j] + dp[j-i])%1000007;
    
    return dp[W]%1000007;
}