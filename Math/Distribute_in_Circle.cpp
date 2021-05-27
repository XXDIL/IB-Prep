/*
    imagine a circular array, indexed from 1
    
    first bring it dowm to 0 indexed then add 1.
*/

int Solution::solve(int A, int B, int C)
{
    return (A+C-2)%B + 1;
}