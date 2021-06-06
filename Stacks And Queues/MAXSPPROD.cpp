/* 
	I had to make this solution because IB wont accept too much memory.

	So i just removed the function calls and used just 1 prod array.
*/
int Solution::maxSpecialProduct(vector<int>& A)
{
	int n = A.size();
	vector<long long> prod(n);
	
	// prev greater element 
	stack<int> S;
    for(int i=0; i<n; ++i)
    {
        while(!S.empty() && A[S.top()] <= A[i]) S.pop();
        
        prod[i] = S.empty() ? 0 : S.top();
        S.push(i);
    }
    
    // next greater element
    S = stack<int>();
    for(int i=n-1; i>=0; --i)
    {
        while(!S.empty() && A[S.top()] <= A[i]) S.pop();

        prod[i] *= S.empty() ? 0 : S.top();
        S.push(i);
    }
	
	int i = max_element(prod.begin(),prod.end()) - prod.begin();
    return prod[i] % 1000000007;
}



/* -------------------------------- A MORE CLEAR SOLUTION ----------------------------------- */

/*
    prevGreater & nextGreater are in Nearest_Smaller_Element.cpp
*/
int soln(vector<int>& A)
{
	int n = A.size();
	vector<int> LG = prevGreater(A, n);
	vector<int> RG = nextGreater(A, n);

	int ans = -1;
	for(int i=0;i<n;++i)
	{
		if(LG[i] == -1 || RG[i] == -1)
			continue;

		ans = max(ans, LG[i]*RG[i]);
	}

	return ans;
}