/* basic fast exp */
long long power(int A, int B, int C)
{
    if(B == 0) return 1;
    
    if(B&1)
        return (A * power(A, B-1, C))%C;
        
    long long temp = power(A, B/2, C);
    return (temp*temp)%C;
}

/* 
    (-x)^(even power) is basically (x)^(even power) but (-x)^(odd power) is not (x)^(odd power)
    keeping this in mind i make a number neg only if A<0 and B is odd.
*/
int Solution::Mod(int A, int B, int C)
{
    if(A == 0) return 0;
    
    // all this for negative numbers
    bool neg = 0;
    if(A<0 && B&1) neg = 1;
    A = abs(A);
    
    if(!neg) return power(A, B, C);
    
    return C - power(A, B, C);
}