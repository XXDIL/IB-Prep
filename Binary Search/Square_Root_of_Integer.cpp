/* Bin Search from 1 to x */
int Solution::sqrt(int x)
{
    int l = 1, h = x;
    while(l <= h)
    {
        int m = l + (h-l)/2;
        long long  m2 = pow(m ,2);
        
        if(m2 == x) return m;
        
        else if(m2 > x) h = m-1;
        else l = m+1;
    }
    
    return h;
}