vector<int> Solution::solve(vector<int> &A)
{
    int n = A.size();
    int Max = A[n-1];
    vector<int> ans = {A[n-1]};
    
    /* 
        the key is to start from the back and keep 
        track of the largest number so far.

        As for a number A[i] to be greater than all
        the numbers it should just be greater than 
        the largest number
    */
    
    for(int i=n-2;i>=0;--i)
    {
        if(A[i] > Max)
        {
            ans.push_back(A[i]);
            Max = A[i];
        }
    }
    
    return ans;
}