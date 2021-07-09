/* simple DP */
vector<vector<int>> Solution::solve(int n)
{
    if(n <= 0) return {};
    if(n == 1) return {{1}};
    
    vector<vector<int>> pt;
    pt.push_back({1});
    
    for(int i=1;i<n;++i)
    {
        vector<int> row(i+1, 1);
        for(int j=1;j<i;++j)
            row[j] = pt[i-1][j] + pt[i-1][j-1];
        pt.push_back(row);
    }
    
    return pt;
}
