/*
    make the presum array and think.

    all we need to do is to increase the speed of lookup, to find the correct pair.
        > enter hashmap
*/

vector<int> Solution::lszero(vector<int> &A)
{
    unordered_map<int, int> M;
    int n = A.size();
    pair<int, int> ans;
    int presum = 0;
    M[0] = -1;

    for(int i=0;i<n;++i)
    {
        presum += A[i];

        if(M.find(presum) != M.end())
        {
            if(ans.first - ans.second < i - M[presum])
                ans = {i, M[presum]};
        }

        else
            M[presum] = i;
    }

    return vector<int>(A.begin()+ans.second+1, A.begin()+ans.first+1);
}