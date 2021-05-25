int Solution::maxSubArray(const vector<int> &A)
{
    // Kadane's Algo
    int GM = A[0], M = A[0];
    int n = A.size();

    for(int i=1;i<n;++i)
    {
        M = max(A[i], M+A[i]);
        GM = max(GM, M);
    }
    
    return GM;
}
