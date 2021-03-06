/*
    keep i = 0 and j = 1.

    make sure i != j at any point
*/

int Solution::solve(vector<int>& A, int B)
{
    sort(A.begin(), A.end());
    int n = A.size();
    
    int i=0, j=1;
    while(i<n && j<n)
    {
        if(i!=j && A[j] - A[i] == B)
            return 1;
            
        if(A[j] - A[i] < B) j++;
        else i++;
    }
    
    return 0;
}