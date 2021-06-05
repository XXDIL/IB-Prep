/*
	sliding window with sum of window
*/
int Solution::solve(vector<int>& A, int B)
{
    int n = A.size();
    int i=0, j=0;
    int ans = 0;
    int presum = A[0];
    
    while(i<n && j<n)
    {
        if(presum < B)
        {
            j++;
            ans += j-i;
            presum += A[j];
        }
        else
        {
            presum -= A[i];
            i++;
        }
    }
    
    return ans;
}