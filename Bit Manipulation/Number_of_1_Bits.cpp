int Solution::numSetBits(unsigned int A) 
{
    int ones = 0;
    for(int i=0;i<32;++i)
    {
        // if the ith bit is 0 then it returns 0 else a number > 0.
        if(A&(1<<i)) 
            ones++;
    }
    
    return ones;
}