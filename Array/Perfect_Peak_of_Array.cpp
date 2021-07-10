/*
    1) per max from left 
    2) pre min from right
    3) logic
*/
int Solution::perfectPeak(vector<int> &A)
{
    int n = A.size();
    int Min[n];
    int Max[n];

    Max[0] = A[0];
    for(int i=1;i<n;++i)
        Max[i] = max(Max[i-1], A[i]);

    Min[n-1] = A[n-1];
    for(int i=n-2;i>=0;--i)
        Min[i] = min(Min[i+1], A[i]);

    for(int i=1;i<n-1;++i)
    {
        if(A[i] > Max[i-1] && A[i] < Min[i+1])
            return 1;
    }

    return 0;
}