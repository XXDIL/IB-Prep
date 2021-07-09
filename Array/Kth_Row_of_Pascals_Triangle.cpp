/* we can do it in 1D DP (just traverse backwards) */
vector<int> Solution::getRow(int k)
{
    if(k < 0) return {};
    if(k == 0) return {1};
    
    vector<int> ans(k+1);
    ans[0] = 1;
    for(int i=1;i<=k;++i)
    {
        for(int j=i;j>=1;--j)
        {
            ans[j] += ans[j-1];
        }
    }

    return ans;
}
