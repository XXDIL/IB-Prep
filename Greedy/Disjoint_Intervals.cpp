/* sort the 2nd column in ascending */
bool cmp(const vector<int> &v1, const vector<int> &v2)
{
    return v1[1] < v2[1];
}

int Solution::solve(vector<vector<int> > &A)
{
    sort(A.begin(), A.end(), cmp);

    int res = 1;
    int endPos = A[0][1];

    for(int i=1; i< A.size(); i++)
        if (A[i][0] > endPos) // think about it
        {
            res++;
            endPos = A[i][1];
        }

    return res;
}