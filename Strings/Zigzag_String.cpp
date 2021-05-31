string Solution::convert(string s, int k)
{
    // base case
    if(k == 1) return s;
    
    // variables
    int n = s.size();
    int sign = 1;
    int i = 0, j = 0;
    string ans = "";
    
    // buckets
    vector<string> groups(k);
    
    /* 
        use the sign logic +-1, observe the trend
        
        s = PAYPALISHIRING   and k = 4

                PAYPALISHIRING
        trend > 01232101232101

        Then simply put them into groups

    */
    while(j < n)
    {
        if(i == k-1) sign = -1;
        if(i == 0) sign = 1;
        
        groups[i] += s[j++];
        i += sign;
    }
    
    // join all the groups
    for(auto i : groups)
        ans += i;
    
    return ans;
}