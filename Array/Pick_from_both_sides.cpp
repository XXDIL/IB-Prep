/* presum array and a little bit of thinking */
int Solution::solve(vector<int> &A, int B)
{
    int n = A.size();

    for(int i=1;i<n;++i)
        A[i] += A[i-1];

    int ans = A[B-1];
    for(int i=2;i<=B;++i)
        ans = max(ans, A[B-i] + A[n-1] - A[n-i]);

    return max(ans, A[n-1] - A[n-B-1]);
}