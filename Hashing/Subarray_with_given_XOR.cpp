/*
    Classic subarray sum, XOR, diff problem

    logic: 
        preXOR^req = B
        req = B^preXOR

        just find req in map
*/
int Solution::solve(vector<int> &A, int B)
{
    int n = A.size();
    unordered_map<int, int> M;
    int ans = 0;
    int preXOR = 0;
    M[0] = 1;

    for(int i=0;i<n;++i)
    {
        preXOR ^= A[i];
        int req = B^preXOR;

        if(M.find(req) != M.end())
            ans += M[req];
        
        M[preXOR]++;
    }

    return ans;
}