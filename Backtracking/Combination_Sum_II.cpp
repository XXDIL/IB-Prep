/*
    Its exactly the same as Combination_Sum.cpp with 1 line(line 16) change.
*/
void help(vector<int>& A, int n, int s, int B, vector<int>& temp, set<vector<int>>& ans)
{
    if(B == 0)
    {
        ans.insert(temp);
        return ;
    }
    
    for(int i=s;i<n;++i)
    {
        if(B < A[i]) return;
        
        if(i>s && A[i] == A[i-1]) continue; // we ignore the repeated elements
        
        else
        {
            temp.push_back(A[i]);
            help(A, n, i+1, B-A[i], temp, ans);
            temp.pop_back();
        }
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
