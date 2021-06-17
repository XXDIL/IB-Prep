/* Sliding window + Map */
vector<int> Solution::dNums(vector<int> &A, int B)
{
    unordered_map<int, int> M;
    int n = A.size();

    int i=0;
    while(i < B)
    {
        M[A[i]]++;
        i++;
    }

    vector<int> ans;
    ans.push_back(M.size());
    
    while(i < n)
    {

        if(M[A[i-B]] == 1)
            M.erase(A[i-B]);
        else 
            M[A[i-B]]--;

        M[A[i]]++;

        ans.push_back(M.size());

        i++;
    }

    return ans;
}