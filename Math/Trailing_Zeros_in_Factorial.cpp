/*
    number of 2's and 5's we need to find is obvious
    but we are going to take min(num_2, num5) but its
    trivial that num_2 >> num_5 (always)
    
    so simply finding the number of 5's is enough
*/
int Solution::trailingZeroes(int A)
{
    /* 
        also we need to find for all powers of 5's 
        
        as some numers like 25, 125 ... have multipe 5's.
    */
    int ans = 0;
    int f = 5;
    while(A/f != 0)
    {
        ans += A/f;
        f *= 5;
    }
    
    return ans;
}
