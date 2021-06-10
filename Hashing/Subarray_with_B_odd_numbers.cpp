/*
    just treat odd numbers as 1 and even as 0.

    then find the number of sub arrays that have a sum of B.
*/
int Solution::solve(vector<int> &A, int B)
{
    int n = A.size();
    int precount = 0;
    unordered_map<int, int> M;
    M[0] = 1;

    int ans = 0;

    for(int i=0;i<n;++i)
    {
        precount += A[i]&1 ? 1 : 0;
        int req = precount - B;

        if(M.find(req) != M.end())
            ans += M[req];
        M[precount]++;
    }

    return ans;
}