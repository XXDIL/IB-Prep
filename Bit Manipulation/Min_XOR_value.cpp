/*
    How to get the min value of XOR?
    
    For 2 number's Xor to be min they need to have 
    very little difference.
*/
int Solution::findMinXor(vector<int> &A)
{
    sort(A.begin(), A.end());
    int ans = INT_MAX;
    int n = A.size();
    for(int i=0;i<n-1;++i)
        ans = min(ans, A[i]^A[i+1]);
        
    return ans;
}