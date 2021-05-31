/*
    Cancer Question

    - discards all leading whitespaces
    - sign of the number
    - overflow
    - invalid input
*/

int Solution::atoi(const string s)
{
    int n = s.size();
    
    // removing leading whitespaces
    int i = 0;
    while(i < n && s[i] == ' ') i++;
    
    // checking the sign
    int neg = 1;
    if(s[i] == '-')
    {
        neg = -1;
        i++;
    }
    else if(s[i] == '+') i++;
    
    long ans = 0;
    while(s[i] >= '0' && s[i] <= '9')
    {
        ans = 10*ans + int(s[i]-'0');
        
        if(INT_MIN >= neg*ans) return INT_MIN;
        if(INT_MAX <= neg*ans) return INT_MAX;
        
        i++;
    }
            
    return neg*ans;
}