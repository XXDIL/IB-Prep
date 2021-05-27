/*
    for a base 10 number
        4321 = 10^3*4 + 10^2*3 + 10^1*2 + 1
    
    similarly here we have a base 26 number
        DCBA = 26^3*D + 26^2*C + 26^1*B + A
        
    where [A - Z] = [1 - 26]
*/

int Solution::titleToNumber(string A)
{
    int n = A.size();
    int ans = 0;
    
    for(int i=n-1;i>=0;--i)
        ans += pow(26, n-1-i)*(A[i]-'A'+1);
    
    return ans;
}
