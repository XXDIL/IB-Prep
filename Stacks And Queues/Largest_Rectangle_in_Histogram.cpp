/*
    the idea is that each histogram can act as the minimum height for max area.
    watch from 4:15 -> https://www.youtube.com/watch?v=vcv3REtIvEo

    find prevminimum() ->  G
    find nextminimum() -> val

    area = A[i]*(val-G[i]-1)
*/
int Solution::largestRectangleArea(vector<int>& A)
{
    int n = A.size();
    stack<int> S;
    vector<int> G(n);
    
    // immediate min element to the left
    for(int i=0;i<n;++i)
    {
        while(!S.empty() && A[S.top()] >= A[i]) S.pop();
        
        G[i] = S.empty() ? -1 : S.top();
        S.push(i);
    }
    
    S = stack<int>();
    int ans = 0;
    // immediate min element to the right
    for(int i=n-1;i>=0;--i)
    {
        while(!S.empty() && A[S.top()] >= A[i]) S.pop();
        
        int val = S.empty() ? n : S.top();
        
        ans = max(ans, A[i]*(val-G[i]-1)); // to quickly find the answer
        
        S.push(i);
    }
    
    return ans;
}