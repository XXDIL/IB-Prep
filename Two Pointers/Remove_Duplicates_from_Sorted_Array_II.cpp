/* 
    Just use 3 pointers
        k to keep track of where to replace
        i for start of repeated nums
        j for end of repeated nums
*/
int Solution::removeDuplicates(vector<int> &A)
{
    int n = A.size();
    int i=0, j=0, k=0;
    
    while(j < n)
    {
        if(A[i] != A[j])
        {

            A[k++] = A[i];                    
            if(j-i > 1)
                A[k++] = A[i];
            
            i = j;
        }
        else j++;
    }

    A[k++] = A[i];
    if(j-i > 1)
        A[k++] = A[i];
    
    return k;
}