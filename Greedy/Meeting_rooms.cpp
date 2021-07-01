/* sortin should come to mind, but u need to get the min meeting ending time so use min heap */
int Solution::solve(vector<vector<int> > &A)
{
    sort(A.begin(), A.end());

    priority_queue<int, vector<int>, greater<int>> H;
    H.push(A[0][1]);
    int ans = 1;

    for(int i=1;i<A.size();++i)
    {
        if(H.top() <= A[i][0]) H.pop();
        else ans++;

        H.push(A[i][1]); 
    }

    return ans;
}