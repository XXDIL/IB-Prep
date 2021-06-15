vector<int> Solution::nextPermutation(vector<int>& A)
{
    int n = A.size();
    
    // find the 1st dec num from the right
    int i = n-2;
    while(i >= 0 && A[i] >= A[i+1]) i--;
            
    // for [4,3,2,1] case i will be -1 and we need to return the sorted array back
    if(i < 0)
    {
        sort(A.begin(), A.end());
        return A;
    }
    
    /*
        find the 1st ele smaller than A[i], then take the element prev to it.
        (basically the 1st element thats just bigger than A[i])
    */
    int j = i+1;
    while(j<n && A[i] < A[j]) j++;
    j--;

    swap(A[i], A[j]);

    // reverse the elements from i+1 to the end
    reverse(A.begin() + i+1, A.end());
    
    return A;
}
