/*
    think of A array as 
        A: [1,5,7,0,0]
        B: [4,6] 

    and start from back of both arrays.
*/

void Solution::merge(vector<int>& A, vector<int>& B)
{
    int m = A.size(), n = B.size();
    A.resize(m+n);
    int i=m-1, j=n-1, k=m+n-1;
    
    while(i >= 0 && j >= 0)
    {
        if(A[i] > B[j])
            A[k] = A[i--];
        else
            A[k] = B[j--];
        
        k--;
    }
    
    while(j >= 0)
    {
        A[k] = B[j--];
        k--;
    }
}