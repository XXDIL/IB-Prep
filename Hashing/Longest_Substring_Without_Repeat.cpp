/*
    Think 2 ptr and sliding window

    keep removing from the set untill the element
    that was repeated is removed.
*/
int Solution::lengthOfLongestSubstring(string s)
{
    int n = s.size();
    unordered_set<char> H;
    int ans = 0;
    
    int i=0, j=0;
    while(j < n)
    {
        while(H.find(s[j]) != H.end())
            H.erase(s[i++]);
        
        H.insert(s[j++]);
        
        if(ans < H.size())
            ans = H.size();
    }
    
    return ans;
}