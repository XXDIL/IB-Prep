/*
    no need to be too smart, just use a set 
    to keep track of the indices the elements
    are present in, that too in sorted order
*/
vector<int> Solution::solve(vector<int> &A)
{
    int n = A.size();
    unordered_map<int, set<int>> M;
    for(int i=0; i<n; ++i)
    {
        if(M.find(A[i]) == M.end())
            M[A[i]].insert(i);
        else
        {
            M[A[i]].insert(i);
            int ind = *M[A[i]].begin();
            M[A[i]].erase(ind);
            A[ind]++;
            M[A[ind]].insert(ind);
        }
    }
    
    return A;
}