int Solution::solve(vector<vector<int> > &A, int B)
{
    int n = A.size();

    // row sum
    for(int i=0;i<n;++i)
        for(int j=1;j<n;++j)
            A[i][j] += A[i][j-1];

    // col sum
    for(int i=1;i<n;++i)
        for(int j=0;j<n;++j)
            A[i][j] += A[i-1][j];

    int ans = INT_MIN;
    for(int i=B-1;i<n;++i)
    {
        for(int j=B-1;j<n;++j)
        {
            int sum = A[i][j];

            if(j-B >= 0 && i-B >= 0)
                sum = sum - A[i][j-B] - A[i-B][j] + A[i-B][j-B];
            else if(j-B >= 0)
                sum = sum - A[i][j-B];
            else if(i-B >= 0)
                sum = sum - A[i-B][j];

            ans = max(ans, sum);
        }
    }

    return ans;
}