/*
    very similar to Maximal_String.cpp

    just one learning point is, there is no need for a temp 
    variable because we can swpa back the elements to make 
    them same as before and continue recurring 
*/
void help(vector<int> A, int n, int s, int B, vector<vector<int>>& ans)
{
    if(B == 0) return;
    
    for(int i=s; i<n-1;++i)
    {
        for(int j=i+1;j<n;++j)
        {
            swap(A[i], A[j]);
            
            ans.push_back(A);
            help(A, n, i+1, B-1, ans);
            
            swap(A[i], A[j]); // swap back
        }
    }
}
    
vector<vector<int> > Solution::permute(vector<int>& nums)
{
    vector<vector<int>> ans;
    ans.push_back(nums);
    
    int n = nums.size();
    
    help(nums, n, 0, n-1, ans);
    
    return ans;
}
