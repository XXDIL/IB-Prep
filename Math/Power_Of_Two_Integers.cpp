/*
    a^p = n (need to find a and p)
    
    p.log(a) = log(n)
    p = log(n)/log(a)
    
    now we iterate over a from 1 to root(n)
    
    as p>1 and int: 
        p = log(n)/log(root(n))
        p = 2
*/

int Solution::isPower(int n)
{
    int p;
    for(int a=1;a*a<n;++a)
    {
        p = log(n)/log(a);
        
        if(pow(a, p) == n) return 1;
    }
    
    return 0;
}
