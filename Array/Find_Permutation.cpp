/* simple Min Max values */
vector<int> Solution::findPerm(const string s, int n)
{
        int f=1, b=n;
        vector<int> ans;
        
        for(auto i : s)
        {
            if(i == 'I')
            {
                ans.push_back(f);
                f++;
            }
            else
            {
                ans.push_back(b);
                b--;
            }
        }
        
        ans.push_back(b);
        
        return ans;
}
