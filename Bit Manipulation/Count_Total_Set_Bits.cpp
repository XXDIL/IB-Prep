const int  MOD = 1000000007;

/* https://www.youtube.com/watch?v=kU5G5-6xEF4 */
int Solution::solve(int A)
{
    if(A == 0) return 0;
    
    int  p = log(A)/log(2);
    long long  x = pow(2, p);
    
    // (ones above max pow of 2 < A) + (count of left most 1's) + (repeat pattern)
    long long ones = (p*x/2 + A-x+1 + solve(A-x))%MOD;

    return ones;
}