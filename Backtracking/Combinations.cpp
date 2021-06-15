/*
    similar to the include/exclude principle, 
    but if we exclude an element then we increment i.
    else we pursue i till temp.size == k
*/
void help(int n, int k, int s, vector<int>& temp, vector<vector<int>>& ans)
{
    if(temp.size() == k)
    {
        ans.push_back(temp);
        return;
    }
    
    for(int i=s;i<=n;++i)
    {
        temp.push_back(i);
        help(n, k, i+1, temp, ans);
        temp.pop_back(); // dont forget to pop the prev element.
    }
}
    
vector<vector<int> > Solution::combine(int n, int k)
{
    vector<vector<int>> ans;
    vector<int> temp;
    help(n, k, 1, temp, ans);
        
    return ans;
}