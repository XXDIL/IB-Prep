/*
    try it urself, not that hard
*/
int Solution::solve(vector<int> &A, int k)
{
    int n = A.size();
    int i=0, j=0;
    int ans = 0;
    int c0 = 0;
    
    while(j < n)
    {
        if(A[j] == 0)
        {
            if(c0 < k) c0++;
            else
            {
                ans = max(ans, j-i);
                while(A[i] != 0) i++;
                i++;
            }
        }
        j++;
    }
    
    return max(ans, j-i);
}