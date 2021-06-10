/*
    Tricky Question if u want to do it in O(n^2)

    Idea is to make it into a 2sum problem.
    Store the prev indices(value) along with the sum(key).

    then you will have a vector of 4 values just sort them.
*/
vector<int> Solution::equal(vector<int> &A)
{
    int n = A.size();
    unordered_map<int, pair<int, int>> M;
    vector<vector<int>> ans;
    for(int a=0;a<n-1;++a)
    {
        for(int b=a+1;b<n;++b)
        {
            int sum = A[a] + A[b];
            
            if(M.find(sum) == M.end())
                M[sum] = {a, b};
            
            else
            {
                auto prev = M[sum];

                if(a!=prev.first && a!=prev.second && b!=prev.first && b!=prev.second)      // make sure they are not repeated values
                    ans.push_back({prev.first, prev.second, a, b});                         // obv prev values will be smaller than a and b
            }
        }
    }

    sort(ans.begin(), ans.end());
    return ans[0];
}