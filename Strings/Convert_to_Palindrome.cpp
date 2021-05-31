// normal palindrome checker
bool isPalin(string s, int l, int r)
{
    while(l < r)
    {
        if(s[l] != s[r])
            return 0;
        
        l++, r--;
    }
    
    return 1;
}

/*
    The idea is, whenever you find a mismatch

    just exclude one of them and if any of them 
    are palins then return true else false.

    abecbea
     ^   ^  mismatch

    so check ispalin("ecbe") || ispalin("becb")
*/
int Solution::solve(string s)
{
    int n = s.size();
    for(int i=0;i<n/2;++i)
    {
        if(s[i] != s[n-1-i])
            return (isPalin(s, i+1, n-i-1) || isPalin(s, i, n-2-i));
    }
    
    // will reach here iff the string is already a palin
    return 1;
}