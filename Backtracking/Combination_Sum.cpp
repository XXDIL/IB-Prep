/*
    Its pretty much MAGIC!!

    don increment i pointer, when B becomes smaller than the 
    ith eleent in A we backtrack to the previous state
*/
void help(vector<int>& A, int n, int s, int B, vector<int>& temp, set<vector<int>>& ans)
{
    if(B == 0)
    {
        ans.insert(temp);
        return;
    }
    
    for(int i=s;i<n;++i)
    {
        if(B < A[i]) return;
        
        B -= A[i];
        temp.push_back(A[i]);
        
        help(A, n, i, B, temp, ans);
        
        temp.pop_back();  // tipical
        B += A[i];
    }
}
 
vector<vector<int>> Solution::combinationSum(vector<int> &A, int B)
{
    sort(A.begin(), A.end());
    
    set<vector<int>> ans;
    vector<int> temp;
    
    help(A, A.size(), 0, B, temp, ans);
    
    return vector<vector<int>>(ans.begin(), ans.end());
}