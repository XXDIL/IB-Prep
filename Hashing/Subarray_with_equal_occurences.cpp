/*
    Transform the problem by changing
        A[i] == B -> A[i] = -1
        A[i] == C -> A[i] = 1
        else -> A[i] = 0

    Then find the number of subarrays with sum = 0;
*/
int Solution::solve(vector<int> &A, int B, int C)
{
    int n = A.size();
    for(int i=0;i<n;++i)
    {
        if(A[i] == B) A[i] = -1;
        else if(A[i] == C) A[i] = 1;
        else A[i] = 0;
    }

    unordered_map<int, int> M;
    M[0] = 1;
    int ans = 0;
    int presum = 0;
    for(int i=0;i<n;++i)
    {
        presum += A[i];
        int req = presum;  // you can replace req with presum thats fine

        if(M.find(req) != M.end())
            ans += M[req];
        M[presum]++;
    }

    return ans;
}