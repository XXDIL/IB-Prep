/* 
    keep count of the frequency of majority element
    c++ if its the me 
    else c--

    and if c == 0 A[i] becomes the me
 */
int Solution::majorityElement(const vector<int> &A)
{
    int n = A.size();
    int me = A[0];
    int c = 1;
    
    for(int i=1;i<n;++i)
    {
        if(A[i] == me)
        {
            c++;
            continue;
        }
        
        if(c == 0)
        {
            me = A[i];
            c = 1;
        }
        
        c--;
    }
    
    return me;
}