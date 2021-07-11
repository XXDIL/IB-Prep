/*
    892795
        ^ <- i
    892759  (reverse)
    
    find a number bigger than A[i-1] (ie 7 in this case)
    
    892759
       ^ ^   9 is bigger than 7 so swap
       
    892957  <- Answer
*/

string Solution::solve(string A)
{
    int n = A.size();
    
    // find the index where there is scope of swapping
    int i=n-1;
    while(i>0 && A[i-1] >= A[i])
        --i;
    
    // string terminated ie not possible to generate
    if(i == 0) return "-1";

    // reverse the string from ith index to the end
    reverse(A.begin()+i, A.end());
    
    // find the first number bigger than A[i-1]
    for(int j=i;j<n;++j)
    {
        if(A[j] > A[i-1])
        {
            swap(A[j], A[i-1]);
            return A;
        }
    }
 }
