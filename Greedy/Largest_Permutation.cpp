/* 
    using a map to store the index of the element is best 

    remember the end state is [5,4,3,2,1]
    and if there are 2 swaps then [5,4,X,X,X]
*/
vector<int> Solution::solve(vector<int> &A, int B)
{
    int n = A.size();

    vector<int> M(n+1);
    for(int i=0;i<n;++i)
        M[A[i]] = i;

    int i = 0;
    while(i<n && B)
    {
        if(A[i] == n-i)
        {
            ++i;
            continue;
        }

        M[A[i]] = M[n-i];
        swap(A[i], A[M[n-i]]);
        B--;
        ++i;
    }

    return A;
}