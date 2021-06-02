/*
	The median of the array will have n/2 elements to the
	left and right of it (given the array is odd).

	for better understanding look at this : https://www.geeksforgeeks.org/find-median-row-wise-sorted-matrix/
*/

int Solution::findMedian(vector<vector<int>> &M)
{
    int m = M.size(), n = M[0].size();

	// find Min and Max elements
	int Min = INT_MAX, Max = INT_MIN;
	for(int i=0;i<m;++i)
	{
		Min = min(Min, M[i][0]);
		Max = max(Max, M[i][n-1]);
	}
		
	int half = (m*n)/2 + 1;
	int l = Min, h = Max;
	while(l < h)
	{
	    int mid = l + (h-l)/2;
		int val = 0;
		
		for(int j=0;j<m;++j)
			val += upper_bound(M[j].begin(), M[j].end(), mid) - M[j].begin();
			
		if(val < half) l = mid+1;
		else h = mid;
	}

	return l;
}