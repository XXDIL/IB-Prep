/* use a vector/array as a map */
int Solution::repeatedNumber(const vector<int> &A)
{
    int n = A.size();
    int M[n];
    for(int i=0;i<n;++i) M[i] = 0;

    for(int i : A)
    {
        M[i-1]++;
        if(M[i-1] > 1)
            return i;
    }

    return -1;
}

/* 
	Another variation is if you can use the input array as the map.
	just mark the elements that have already been read using -ve sign
*/
vector<int> findDuplicates(vector<int>& A)
{
    int n = A.size();
    vector<int> ans;

    for(int i=0;i<n;++i)
    {
        int x = abs(A[i])-1;
        if(A[x] < 0)
            ans.push_back(abs(A[i]));
        else
            A[x] *= -1;
    }

    return ans;
}
