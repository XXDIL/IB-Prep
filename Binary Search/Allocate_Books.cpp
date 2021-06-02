/* 
    returns the number of groups the books can be made into
    given the limit of cMax pages per group.
*/ 
int studentCount(vector<int> A, int n, int cMax)
{
	int c=0, i=0, s=0;
	while(i < n)
	{
		if(s + A[i] <= cMax)
		{
			s += A[i];
			i++;
		}
		else
		{
			c++;
			s = 0;
		}
	}

	return c+1;
}

/*
    Beautiful question, that opens up a very different
    implementation of Binary Search.
    
    watch : https://www.youtube.com/watch?v=2JSQIhPcHQg
*/
int Solution::books(vector<int>& A, int B)
{
    int n = A.size();
	int l=-1, h=0;
	
	for(int i=0;i<n;++i)
	{
	    l = max(l, A[i]);
	    h += A[i];
	}
	
	// Corner cases
	if(B > n) return -1;
	if(B == n) return l;

    int res = l;
	while(l <= h)
	{
		int m = l + (h-l)/2;
		int c = studentCount(A, n, m);

		if(c == B)
		{
			res = m;
			h = m-1;
		}

		else if(c < B) h = m-1;
		else l = m+1;
	}

	return res;
}