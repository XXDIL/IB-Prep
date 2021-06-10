/*
    to satisfy the constraints of the answer vector.

    first we can update the map till the ith index
        so it satisfies the i<j criterion

    map stores the {B-A[i] value and index of A[i]}

    then we check if there is A[i] is in map 
        if there is then we have found the answer
        else
            we check if there is B-A[i] in map
                if not then we add B-A[i] to the map with the index of A[i]
    
*/
vector<int> Solution::twoSum(const vector<int>& A, int B)
{
    unordered_map<int, int> M;
    int n = A.size();
    for(int i=0;i<n;++i)
    {
        if(M.find(A[i]) == M.end())
            if(M.find(B-A[i]) == M.end())
                M[B-A[i]] = i;
    
        else
            return {M[A[i]]+1, i+1};
    }
    
    return {};
}