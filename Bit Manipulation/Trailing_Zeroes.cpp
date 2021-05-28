int Solution::solve(int A)
{
    int x = A^(A-1);
    
    // get the msb using log base 2
    return log2(x);
}