/*
    Sliding window logic
*/
string Solution::solve(string A, int B)
{
    int n = A.size();
    int i=0, j=0;
    string ans = "";
    
    while(j < n)
    {
        while(A[i] == A[j]) j++;
        
        if(j-i != B)
            ans += string(j-i, A[i]);
        
        i = j;
    }

    return ans;
}