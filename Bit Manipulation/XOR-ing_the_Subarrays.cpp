/*
    for n = 5
    [a, b, c, d, e]
    
    len 1 subarrays = a,b,c,d,e  <-------+
    len 2 subarrays = ab,bc,cd,de  <--+  |
    len 3 subarrays = abc,bcd,cde     |  |
    len 4 subarrays = abcd,bcde    <--+  |
    len 5 subarrays = abcde      <-------+
    
    those groups cancel each other, using : x^x = 0
    
    so for even length arrays it will all cancel out.
    
    For odd its the XOR of the alternate terms in the array.
*/

int Solution::solve(vector<int> &A)
{
    int n = A.size();
    if(n%2 == 0) return 0;
    
    int ans = 0;
    for(int i=0;i<n;i+=2)
        ans ^= A[i];
        
    return ans;
}