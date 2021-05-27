/*
    recurrance relation:
        gcd(a, b) = a           if b == 0
                    gcd(b, a%b) else
*/
int Solution::gcd(int A, int B)
{
    if(B == 0) return A;
    
    return gcd(B, A%B);
}
