unsigned int Solution::reverse(unsigned int A)
{
    unsigned int ans = 0;
    
    for(int i=0;i<32;++i)
    {
        if(A&(1<<i))
            ans += pow(2, 31-i);
    }
    
    return ans;
}