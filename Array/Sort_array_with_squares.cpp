vector<int> Solution::solve(vector<int> &A)
{
    /*
        as the array is sorted in ascending order
        we can use 2 pointer approach
        
        l++ if abs(A[r]) < abs(A[l])
        else r-- 
        
        in a new array insert from the right
    */
    int n = A.size();
    vector<int> ans(n);
    int i = 0, j = n-1;
    
    int a = n;
    while(a--)
    {
        if(abs(A[j]) < abs(A[i]))
        {
            ans[a] = A[i]*A[i];
            i++;
        }
        else
        {
            ans[a] = A[j]*A[j];
            j--;
        }
    }
    
    return ans;
}
