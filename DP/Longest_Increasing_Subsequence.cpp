/*
    No Recursion for this, but the idea is to start left to right.
    n^2 logic.
*/
int Solution::lis(const vector<int> &A)
{
    int n = A.size();
    int dp[n];
    dp[0] = 1;
    
    for(int i=1;i<n;++i)
    {
        int M = -1; // -1 incase we cant increase the size of the LIS
        for(int j=0;j<i;++j)
        {
            if(A[i] > A[j] && M < dp[j]) 
                M = dp[j];
        }
        
        dp[i] = M==-1 ? 1 : M+1;
    }
    
    return *max_element(dp, dp+n);
}