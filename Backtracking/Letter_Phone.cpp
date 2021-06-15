unordered_map<char, string> M = {   {'0', "0"}, {'1', "1"},
                                    {'2', "abc"}, {'3', "def"}, 
                                    {'4', "ghi"}, {'5', "jkl"}, 
                                    {'6', "mno"}, {'7', "pqrs"}, 
                                    {'8', "tuv"}, {'9', "wxyz"}};

/*
    nothing much to explain, just make the recursive tree u will get it.
*/                                  
void help(string A, int n, int s, string temp, vector<string>& ans)   
{
    if(s == n)
    {
        ans.push_back(temp);
        return;
    }
    
    for(auto i : M[A[s]])
    {
        temp += i;
        help(A, n, s+1, temp, ans);
        temp.pop_back();
    }
}
    
vector<string> Solution::letterCombinations(string A)
{
    if(A.size() == 0) return {};
    
    vector<string> ans;
    string temp;
    
    help(A, A.size(), 0, temp, ans);
    
    return ans;
}