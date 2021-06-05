/* Quite simple if u have seen it b4 */
int Solution::maxArea(vector<int> &A)
{
    int n = A.size();
    int l = 0, r = n-1;
    int ans = 0;
    
    while(l < r)
    {
        if(A[l] < A[r])
        {
            ans = max(ans, (r-l)*A[l]);
            l++;
        }
        
        else
        {
            ans = max(ans, (r-l)*A[r]);
            r--;
        }
    }
    
    return ans;
}
