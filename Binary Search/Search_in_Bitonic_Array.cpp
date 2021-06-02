#include<bits/stdc++.h>
using namespace std;

int findPeak(vector<int> A, int n)
{
    int l = 0, h = n-1;
    while(l < h)
    {
        int m = l + (h-l)/2;

        if(A[m] > A[m+1]) h = m;
        else l = m+1;
    }
    
    return l;
}

int binSearchForward(vector<int> A, int l, int r, int ele)
{
	while(l <= r)
	{
		int m = l + (r-l)/2;

		if(A[m] == ele)
			return m;

		if(ele > A[m]) l = m+1;
		else r = m-1;
	}

	return -1;
}

int binSearchReverse(vector<int> A, int l, int r, int ele)
{
	while(l <= r)
	{
		int m = l + (r-l)/2;

		if(A[m] == ele)
			return m;

		if(ele > A[m]) r = m-1;
		else l = m+1;
	}

	return -1;
}

int soln(vector<int>& A, int target)
{
	int n = A.size();
	int peak = findPeak(A, n);

	int left = binSearchForward(A, 0, peak, target);
	if(left != -1)
		return left;

	return binSearchReverse(A, peak+1, n-1, target);
}

int main()
{
	vector<int> b = {3, 9, 10, 20, 17, 5, 1};
	for(int i=0;i<7;++i)
		cout << soln(b, b[i]) << endl;

	cout << soln(b, 0) << endl;
	cout << soln(b, 25) << endl;
	cout << soln(b, 8) << endl;
	cout << soln(b, 6) << endl;

	return 0;
}