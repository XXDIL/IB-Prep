/* basic palin checker */
bool isPalin(vector<string> strs)
{
    for(auto s : strs)
    {
        for(int i=0;i<s.size()/2;++i)
            if(s[i] != s[s.size()-1-i])
                return 0;
    }
    
    return 1;
}

/*
    Recursive tree : 
                    aab
         a          aa      aab
    a,a    a,ab    aa,b     
   a,a,b
*/
void help(string str, int s, vector<string>& temp, vector<vector<string>>&ans)
{
    if(s == str.size() && isPalin(temp))
    {
        ans.push_back(temp);
        return;
    }
    
    for(int i=s;i<str.size();++i)
    {
        temp.push_back(str.substr(s, i-s+1));
        help(str, i+1, temp, ans);
        temp.pop_back();
    }
}

vector<vector<string>> partition(string s)
{
    vector<vector<string>> ans;
    vector<string> temp;
    
    help(s, 0, temp, ans);
    
    return ans;
}