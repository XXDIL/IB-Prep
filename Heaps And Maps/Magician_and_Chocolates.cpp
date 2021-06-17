/*
    Too easy if u know we need to use a heap.
*/
int Solution::nchoc(int B, vector<int>& A)
{
    int n = A.size();
    priority_queue<int> maxh(A.begin(), A.end());

    long long ans = 0;
    while(B--)
    {
        int top = maxh.top();

        ans += top%1000000007;

        maxh.pop();
        maxh.push(top/2);
    }

    return ans%1000000007;
}