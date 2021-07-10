/*
    find LIS 
    find LDS (LIS in reverse)

    take max of LIS[i] + LDS[i] - 1
*/
int Solution::longestSubsequenceLength(const vector<int> &A)
{
    int n = A.size();
    int dp1[n];
    int dp2[n];
    dp1[0] = dp2[n-1]= 1;

    // LIS
    for(int i=1;i<n;++i)
    {
        int M = -1;
        for(int j=0;j<i;++j)
        {
            if(A[i] > A[j])
                M = max(M, dp1[j]);
        }
        dp1[i] = M==-1 ? 1 : M+1;
    }

    // LDS
    for(int i=n-2;i>=0;--i)
    {
        int M = -1;
        for(int j=n-1;j>i;--j)
        {
            if(A[i] > A[j])
                M = max(M, dp2[j]);
        }
        dp2[i] = M==-1 ? 1 : M+1;
    }

    // max of LIS[i] + LDS[i] -1
    int ans = 0;
    for(int i=0;i<n;++i)
        ans = max(ans, dp1[i] + dp2[i] -1);
    
    return ans;
}