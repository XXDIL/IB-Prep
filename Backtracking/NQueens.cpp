/*
    my own explaination : https://leetcode.com/problems/n-queens/discuss/1225450/C%2B%2B-Just-BFS-and-O(n)-space-Logic
*/

bool is_safe(vector<int>& curr, int n, int j)
{
    for(int i=0;i<j;++i)
    {
        if(curr[i] == curr[j]) return 0;
        
        if(i+curr[i] == j+curr[j]) return 0;
        
        if(i-curr[i] == j-curr[j]) return 0;
    }
    
    return 1;
}
 
vector<vector<string>> Solution::solveNQueens(int n)
{
    if(n == 2 || n == 3) return {};
    
    vector<vector<string>> res;
    
    vector<int> start(n, -1);
    queue<vector<int>> frontier;
    
    frontier.push(start);
            
    while(!frontier.empty())
    {
        auto curr = frontier.front();
        frontier.pop();
          
        // finding the vacant column
        int j=0;
        while(j < n && curr[j] != -1) j++;
        
        if(j == n) // found the end state
        {
            vector<string> ans(n, string(n, '.'));
            for(int i=0;i<n;++i)
                ans[i][curr[i]] = 'Q';
            
            res.push_back(ans);
            continue;
        }
             
        // generating valid children
        for(int i=0;i<n;++i)
        {
            vector<int> child = curr;
            child[j] = i;
            
            if(is_safe(child, n, j))
                frontier.push(child);
        }
    }
    
    return res;
}