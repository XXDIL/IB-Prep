/*
    just use a map to store 
        value and index or 
        value and count

    either works
*/
int Solution::diffPossible(const vector<int> &A, int B)
{
    int n = A.size();
    unordered_map<int, int> M;
    for(int i=0;i<n;++i)
    {
        if(M.find(A[i]) == M.end())
        {
            if(M.find(B + A[i]) == M.end())
                M[B + A[i]]++;

            if(M.find(A[i] - B) == M.end())
                M[A[i] - B]++;
        }

        else return 1;
    }

    return 0;
}