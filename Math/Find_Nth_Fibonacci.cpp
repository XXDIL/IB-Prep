#define MOD 1000000007

vector<vector<long>> multiply(vector<vector<long>> A, vector<vector<long>> B)
{
    vector<vector<long>> prod(2, vector<long>(2));
    
    prod[0][0] = ((A[0][0]*B[0][0])%MOD + (A[0][1]*B[1][0])%MOD)%MOD;
    prod[0][1] = ((A[0][0]*B[0][1])%MOD + (A[0][1]*B[1][1])%MOD)%MOD;
    prod[1][0] = ((A[1][0]*B[0][0])%MOD + (A[1][1]*B[1][0])%MOD)%MOD;
    prod[1][1] = ((A[1][0]*B[0][1])%MOD + (A[1][1]*B[1][1])%MOD)%MOD;
    
    return prod;
}

/*
    using an effecient way to find the power of a number 

    Recurrance relation:
        a^b = a^(b/2) * a^(b/2)   if b is even
              a * a^(b-1)         if b is odd
              a                   if b == 1;
*/

vector<vector<long>> power(vector<vector<long>> F, int n)
{
    if(n == 1) return F;
    
    if(n%2 == 0)
    {
        vector<vector<long>> temp = power(F, n/2);
        return multiply(temp, temp);
    }
    
    else
        return multiply(F, power(F, n-1));
}

/*
    1 1              fn+1  fn
    1 0  represents  fn    fn-1

    if they ask for MOD (cancer) then just make the matrix long.

    you can also try with [1, 1, 1, 0] instead of a 2D matrix.
*/

int Solution::solve(int n)
{
    vector<vector<long>> F = {{1, 1}, {1, 0}};
    
    F = power(F, n-1);
    
    return F[0][0];
}