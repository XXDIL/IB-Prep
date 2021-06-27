/*
    Its not intuitive but it has a similar solution to next greater element.
*/
int Solution::solve(vector<int> &A)
{
    int n = A.size();
    stack<int> S;
    int root = INT_MIN;

    for(int i=0;i<n;++i)
    {
        if(A[i] < root) return 0;

        while(!S.empty() && S.top()<A[i])
        {
            root = S.top();
            S.pop();
        }

        S.push(A[i]);
    }

    return 1;
}