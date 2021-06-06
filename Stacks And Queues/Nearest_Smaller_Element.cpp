/*
	I put all 3 here just to show the variation.

	FOR GREATER -> monotonically INCREASING Stack
	FOR SMALLER -> monotonically DECREASING Stack
*/

vector<int> Solution::prevSmaller(vector<int> &A)
{
    int n = A.size();
    stack<int> S;
    vector<int> G(n);
    
    for(int i=0;i<n;++i)
    {
    	while(!S.empty() && A[S.top()] >= A[i]) S.pop();
    
    	G[i] = S.empty() ? -1 : A[S.top()];
    	S.push(i);
    }
    
    return G;
}

vector<int> prevGreater(vector<int>& A, int n)
{
    stack<int> S;
    vector<int> G(n);
    
    for(int i=0; i<n; ++i)
    {
        while(!S.empty() && A[S.top()] <= A[i]) S.pop();
        
        G[i] = S.empty() ? -1 : S.top();
        S.push(i);
    }
    
    return G;
}

vector<int> nextGreater(vector<int>& A, int n)
{
    stack<int> S;
    vector<int> G(n);
    
    for(int i=n-1; i>=0; --i)
    {
        while(!S.empty() && A[S.top()] <= A[i]) S.pop();

        G[i] = S.empty() ? -1 : S.top();
        S.push(i);
    }
    
    return G;
}
