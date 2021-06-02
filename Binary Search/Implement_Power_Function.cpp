/* normal fast power function modified to fit long long */ 
long long power(int a, int b, int c)
{
    if(b == 0) return 1;
    
    if(b&1) // odd
        return (a*power(a, b-1, c))%c;
    else
    {
        long long temp = power(a, b/2, c);
        return (temp*temp)%c;
    }
}

int Solution::pow(int a, int b, int c)
{
    // base cases
    if(a == 0) return 0;
    if(a == 1 || b == 0) return 1;
    
    long long ans = power(a, b, c);
    
    // a can be -ve (-1**1)%5 == 4
    if(ans < 0)
        return ans + c;
    return ans;
}