/* 
    Requires a little thinking, the jist is that maintain a pointer
    that will get toses elements != val and when found, 
    replace it with the previous pointer
*/

int Solution::removeElement(vector<int>& A, int val)
{
    int n = A.size();
    int i=0, j=0;
    
    while(i < n && j < n)
    {
        if(A[i] != val)
        {
            A[j] = A[i];
            j++;
        }
        
        i++;
    }
    
    return j;
}