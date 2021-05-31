/* similar to "Remove_Consecutive_Characters.cpp" */
string CAS(string s)
{
    int n = s.size();
    int i=0, j=0;
    string ans = "";
    
    while(j < n)
    {
        while(s[i] == s[j]) j++;
        
        ans += to_string(j-i) + s[i];
        
        i = j;
    }
    
    return ans;
}
string Solution::countAndSay(int n)
{
    string ans = "1";
    while(--n)
        ans =  CAS(ans);
    
    return ans;
}