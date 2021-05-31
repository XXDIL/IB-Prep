/* Start from back of the string */
int Solution::romanToInt(string s)
{
    unordered_map<char, int> symbols({{'I', 1}, {'V', 5}, {'X', 10}, {'L', 50}, 
                                          {'C', 100}, {'D', 500}, {'M', 1000}});
        
    int n = s.size();
    int ans = symbols[s[n-1]];
    
    for(int i=n-2;i>=0;--i)
    {
        if(symbols[s[i]] < symbols[s[i+1]]) ans -= symbols[s[i]];
        
        else ans += symbols[s[i]];
    }
    
    return ans;
}