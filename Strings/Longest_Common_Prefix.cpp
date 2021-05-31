string prefix(string a, string b)
{        
    int i = 0;
    while(i<a.size() && a[i] == b[i]) i++;
    
    return a.substr(0, i);
}

string Solution::longestCommonPrefix(vector<string>& strs) 
{
    int n = strs.size();
    if(n == 1) return strs[0];
    
    string ans = prefix(strs[0], strs[1]);
    
    for(int i=2;i<n;++i)
        ans = prefix(ans, strs[i]);
    
    return ans;
}