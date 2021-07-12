/*
    A lot of clever math, but the main idea is that we only
    need to divide by 2 again and again till we reach 2 or 
    there is an odd number encountered.
*/
int Solution::power(string A)
{
    if(A == "0" || A == "1")
        return 0;
    while(1)
    {
        if(A == "2")
            return 1;
        
        if((A.back()-'0')%2 != 0)
            return 0;

        int n = A.size();

        int carry = 0;
        for(int i=0;i<n;++i)
        {
            int d = A[i]-'0';
            A[i] = '0' + (10*carry + d)/2;

            carry = d%2;
        }

        // remove leading 0
        if(A[0] == '0')
            A = A.substr(1, n-1);
    }
    return -1;
}