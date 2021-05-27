// just make it a string problem lol
int Solution::reverse(int A)
{
    string strA = to_string(A);
    std::reverse(strA.begin(), strA.end());
    
    int n = strA.size();
    int neg = 1;
    if(strA[n-1] == '-')
    {
        neg = -1;
        strA.pop_back();
    }
    
    long ans = neg*stol(strA);
    
    return (ans > INT_MAX || ans < INT_MIN) ? 0 : ans;
}