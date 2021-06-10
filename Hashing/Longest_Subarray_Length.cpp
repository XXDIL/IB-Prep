/*
    make all 0's = -1
    
    now the question is longest subarray with sum = k
    
    in our case k = 1;
*/
int Solution::solve(vector<int> &A)
{
    int n = A.size();
    for(int i=0;i<n;++i)
        if(A[i] == 0) A[i] = -1;

    unordered_map<int, int> M;
    int presum = 0;
    int len = 0;
    M[0] = -1;
    for(int i=0;i<n;++i)
    {
        presum += A[i];
        int req = presum - 1; // presum - k = presum - 1
 
        if(M.find(presum) == M.end())
            M[presum] = i;
 
        if(M.find(req) != M.end())
            len = max(len, i - M[req]);
    }
 
    return len;
}