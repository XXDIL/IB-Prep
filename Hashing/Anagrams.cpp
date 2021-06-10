/*
    sort the strings to form the key
*/
vector<vector<int> > Solution::anagrams(const vector<string>& strs)
{
    unordered_map<string, vector<int>> M;
    for(int i=0;i<strs.size();++i)
    {
        string temp_str = strs[i];
        sort(temp_str.begin(), temp_str.end());
        M[temp_str].push_back(i+1);
    }
    
    vector<vector<int>> ans;
    for(auto i : M)
        ans.push_back(i.second);
        
    return ans;
}