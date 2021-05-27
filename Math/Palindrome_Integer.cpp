/*
    convert to string
*/
int Solution::isPalindrome(int A)
{
    string strA = to_string(A);
    int n = strA.size();
    
    for(int i=0;i<n/2;++i)
    {
        if(strA[i] != strA[n-1-i])
            return 0;
    }
    
    return 1;
}