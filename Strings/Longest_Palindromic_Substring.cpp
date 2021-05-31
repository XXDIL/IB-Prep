string Solution::longestPalindrome(string s)
{
    
    int n = s.size();
    vector<vector<bool>> dp(n, vector<bool>(n));
    int len = 1;
    
    // length 1
    for(int i=0;i<n;++i) dp[i][i] = 1;
    // length 2
    for(int i=0;i+1<n;++i)
        if(s[i] == s[i+1])
        {
            dp[i][i+1] = 1;
            
            // also mark the max length
            len = 2;
        }
    
    for(int i=0;i<n-2;++i)
    {
        int si = 0, sj = 2+i;
        while(sj < n)
        {
            if(s[si] == s[sj] && dp[si+1][sj-1])
            {
                dp[si][sj] = 1;
                
                 
                len = sj-si+1;
            }
            
            si++, sj++;
        }
    }
    
    
    // max length palin lies in diagonal "len".
    int i=0, j = len-1;
    while(j < n)
    {
        if(dp[i][j])
            return s.substr(i, j-i+1);
        i++, j++;
    }
                    
    return "XXDIL";
}