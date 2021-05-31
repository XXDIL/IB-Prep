// same LPS Array generation code
vector<int> LPS(string s)
{
	int n = s.size();
	vector<int> lps(n);
	int i=1,j=0;

	while(i < n)
	{
		if(s[i] == s[j])
		{
			lps[i] = j+1;
			i++, j++;
		}
		else
		{
			if(j == 0) i++;
			else j = lps[j-1];
		}
	}

	return lps;
}

/* Slight modification to Minimum_Appends_for_Palindrome.cpp */

int Solution::solve(string s)
{
    string rs = s;
	reverse(rs.	begin(), rs.end());

	vector<int> lps = LPS(s+"|"+rs);

	return s.size()-lps.back();
}