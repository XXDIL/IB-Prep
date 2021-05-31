int ispalin(string A)
{
    int n = A.size();
    
    for(int i=0;i<=(n/2)-1;++i)
    {
        if(A[i] != A[n-i-1]) return 0;
    }
    
    return 1;
}

int Solution::isPalindrome(string A)
{
    int n = A.size();
    
    string newA = "";
    
    // input sanitization
    for(int i=0;i<n;++i)
    {
        if(isalnum(A[i]))
        {
            if(isalpha(A[i])) A[i] = tolower(A[i]);
            
            newA += A[i];
        }
    }
    
    return ispalin(newA);
}