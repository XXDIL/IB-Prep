int Solution::solve(vector<int> &A) 
{
    // no other way ig
    sort(A.begin(), A.end());
    int n = A.size();
    int i=0;
    
    // ignore all the negative numbers
    while(i < n && A[i] < 0) ++i;
    
    for(i;i<n;++i)
    {
        // skip all the duplicate values
        while(i+1 < n && A[i] == A[i+1])++i;
        
        // nobel number criterion
        if(A[i]+i == n-1)
            return 1;
    }
    
    return -1;
}
