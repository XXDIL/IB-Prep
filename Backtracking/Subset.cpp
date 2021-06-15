/*
    base case : if the input in empty

    recursion : either include of exclude A[i]
*/
void solve(vector<int>& A, int n, int i, vector<int> temp, vector<vector<int>>& ans)
{
    if(i == n)
    {
        ans.push_back(temp);
        return;
    }
 
    solve(A, n, i+1, temp, ans); // exclude
 
    temp.push_back(A[i]);
    solve(A, n, i+1, temp, ans); // include
}
 
vector<vector<int>> Solution::subsets(vector<int>& A)
{
    vector<vector<int>> ans;
    sort(A.begin(), A.end()); // IB BS
 
    solve(A, A.size(), 0, {}, ans);
    
    sort(ans.begin(), ans.end()); // IB BS
    
    return ans;
}