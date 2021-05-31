void LPS(vector<int>& lps, string p, int n)
{
    int i=1, j=0;
    while(i < n)
    {
        if(p[i] == p[j])
        {
            lps[i] = j+1;
            j++, i++;
        }
        else
        {
            if(j == 0)
                i++;
            else
                j=lps[j-1];
        }
    }
}

/* KMP! Bruhhhh */

int Solution::strStr(const string s, const string p)
{
    int np = p.size();
    int ns = s.size();
    
    // corner cases
    if(np == 0) return 0;
    
    // generate the LPS array
    vector<int> lps(np);
    LPS(lps, p, np);
    
    // string matching
    int i=0, j=0;
    while(i < ns && j < np)
    {
        if(p[j] == s[i])
        {
            i++, j++;
        }
        else
        {
            if(j == 0)
                i++;
            else
                j=lps[j-1];
        }
        
        if(j == np) return i-j;
    }
            
    return -1;
}