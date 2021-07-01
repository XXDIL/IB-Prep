/* 
    a b c d e f g h i j

    max products possible
        1) a*b*j  (negative numbers)
        2) h*i*j
*/
int Solution::maxp3(vector<int> &A)
{
    int n = A.size();
    
    int M1=INT_MIN, M2=INT_MIN, M3=INT_MIN;
    for(int i=0;i<n;++i)
    {
        if(M1 < A[i])
        {
            M3 = M2;
            M2 = M1;
            M1 = A[i];
        }
        
        else if(M2 < A[i])
        {
            M3 = M2;
            M2 = A[i];
        }
        
        else if(M3 < A[i])
        {
            M3 = A[i];
        }
    }
    
    int m1=INT_MAX, m2=INT_MAX;
    for(int i=0;i<n;++i)
    {   
        if(m1 > A[i])
        {
            m2 = m1;
            m1 = A[i];
        }
        
        else if(m2 > A[i])
        {
            m2 = A[i];
        }
    }
    
    return max(M1*M2*M3, M1*m1*m2);
}