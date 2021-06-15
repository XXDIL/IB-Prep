void NextPermute(vector<int>& A)
{
    int n = A.size();

    int i = n-2;
    while(i >= 0 && A[i] >= A[i+1]) i--;

    int j = i+1;
    while(j<n && A[i] < A[j]) j++;
    j--;

    swap(A[i], A[j]);
    reverse(A.begin() + i+1, A.end());
}
/*
    start from [1,2,3,...,n] and keep finding the next permutation till k becomes 0.

    you can try to use std::next_permutation() too.
*/
string Solution::getPermutation(int n, int k)
{
    vector<int> A;
    for(int i=1;i<=n;++i)
        A.push_back(i);
    
    while(--k)
        NextPermute(A); // next_permutation(A.begin(), A.end());
        
    string strA = "";
    for(auto i : A)
        strA += to_string(i);
    
    return strA;
}