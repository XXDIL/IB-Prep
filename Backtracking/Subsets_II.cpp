/*
    same as Subset.cpp but just use a set to get unique elements
*/
void help(vector<int>& A, int n, int i, vector<int>& temp, set<vector<int>>& ans)
{
    if(i == n)
    {
        ans.insert(temp);
        return;
    }
    
    help(A, n, i+1, temp, ans);
    
    temp.push_back(A[i]);
    help(A, n, i+1, temp, ans);
    temp.pop_back();
}
    
vector<vector<int> > Solution::subsetsWithDup(vector<int>& A)
{
    sort(A.begin(), A.end());
    
    set<vector<int>> ans;
    vector<int> temp;
    
    help(A, A.size(), 0, temp, ans);
        
    return vector<vector<int>>(ans.begin(), ans.end());
}
