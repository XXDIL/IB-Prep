/* returns 
    true    if amount of wood >= B
    false   else
*/
bool validWoodCount(vector<int>& A, int n, int B, int height)
{
	int count = 0;
	for(int i=0;i<n;++i)
	{
		count += (A[i]>height) ? A[i]-height : 0;

		if(count >= B) return 1;
	}

	return 0;
}

/* 
    similar to Allocate_Books.cpp
    
    just binSearch(0, max(A))
*/
int Solution::solve(vector<int>& A, int B)
{
    int n = A.size();
	int l = 0;
	int h = *max_element(A.begin(), A.end());
	int res = 0;

	while(l <= h)
	{
		int m = l + (h-l)/2;

		if(validWoodCount(A, n, B, m))
		{
			res = m;
			l = m+1;
		}
		else h = m-1;
	}

	return res;
}