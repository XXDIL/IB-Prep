int Solution::firstMissingPositive(vector<int>& A)
{
    int n = A.size();
    // convert all <1 numbers to n+1 so we can ignore them
    for(int i=0;i<n;i++)
    {
        if(A[i]<1)
            A[i]=n+1;
    }

    /*
        now we have some numbers  
            between [1, n] and,
            numbers >n.

        we simply ignore the umbers >n

        numbers between [1, n] are used as indices by subtracting 1 from them
        [1, n] - 1 = [0, n-1]

        now we can mark those indices(using -ve values) if they have been seen b4.
    */
    for(int i=0;i<n;i++)
    {
        if(abs(A[i])<=n) // the abs(A[i]) is very important
            A[abs(A[i])-1] *= (A[abs(A[i])-1] < 0) ? 1 : -1;
    }

    /* 
        after this step if any number is -ve then the index of that number + 1 has already occured.

        So all we need to do is return the 1st +ve number's index + 1;
    */

    for(int i=0;i<n;i++)
    {
        if(A[i]>0)
            return i+1;
    }

    return(n+1);
}