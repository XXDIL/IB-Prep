#define MOD 1000000007

/*
    Just count the number of vowels
    then multiply vowel count with consonant count.
*/

int Solution::solve(string A) 
{
    int n = A.size();
    int v=0;
    for(int i=0;i<n;i++)
    {
        if(A[i]=='a' || A[i]=='e' || A[i]=='i' || A[i]=='o' || A[i]=='u')
            v++;
    }
    
    return (v*(n-v))%MOD;
}