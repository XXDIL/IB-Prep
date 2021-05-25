vector<int> Solution::wave(vector<int> &A)
{
    int n = A.size();
    int mid = n/2;

    /*
	We can also use Quick Select to find the median element
	and make the array partially sorted about the mid index

	but this will not give the Lexicographically sorted output

	    	nth_element(A.begin(), A.begin()+mid, A.end());
    */

    sort(A.begin(), A.end()); // for Lexicographically sorted order.
        
    vector<int> ans;
    
    int i=mid-1, j=mid; // if you are using Quick select method make sure to change these.
    while(i >= 0)
    {
        ans.push_back(A[j++]);
        ans.push_back(A[i--]);
    }
    
    if(n%2!=0)
        ans.push_back(A[j]);
    
    return ans;
}
