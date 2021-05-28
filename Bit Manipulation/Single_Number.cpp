int Solution::singleNumber(const vector<int> &A)
{
    /*
        a^a = 0
        0^x = x
        
        all equal number pairs will xor to 0 
        then finally we do 0^ans = ans
    */
    int n = A.size();
    int ans = 0;
    
    for(int i=0;i<n;++i)
        ans ^= A[i];
        
    return ans;
}