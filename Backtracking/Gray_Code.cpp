/*
    Screw BT for this problem, trust me ur better off doing it iteratively.

    write down the gray codes for n=4, like a TT.
    notice the column patterns

    0110
    00111100
    0000111111110000...
*/
vector<int> Solution::grayCode(int n)
{
    int N = pow(2, n);
    vector<int> ans(N);
    
    for(int i=0;i<n;++i)
    {
        int s = pow(2, i);
        for(int j=s;j<N;j+=(4*s))
            for(int k=0;k<(2*s);++k)
                if(j+k < N)
                    ans[j+k] += s;
    }
    
    return ans;
}