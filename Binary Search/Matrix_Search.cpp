/*
    search for the row that could contain the target.
    then bin search on that row.
*/
int Solution::searchMatrix(vector<vector<int>>& M, int target)
{
    int m = M.size(), n = M[0].size();
    if(target > M[m-1][n-1]) return 0;
    
    int i = 0;
    while(i < m && M[i][n-1] < target) i++;
    
    return binary_search(M[i].begin(), M[i].end(), target);
}