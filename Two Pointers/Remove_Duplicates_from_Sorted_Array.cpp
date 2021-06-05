/*
    only 2 ptr are required, the 
        1'st ptr will keep a track of the elements that are repeated  
        2'nd ptr will find the next non repeating number.
*/
int Solution::removeDuplicates(vector<int>& A)
{
    int n = A.size();
    if(n == 0) return 0;
    
    int i=0, j=0;
    while(j < n)
    {
        if(A[i] != A[j])
        {
            i++;
            A[i] = A[j];
        }
        
        j++;
    }
    
    return i+1;    
}