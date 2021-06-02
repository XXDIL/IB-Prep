int Occurance(vector<int> A, int B, bool d)
{
    int n = A.size();
    int l=0, h=n-0, res = -1;
    while(l <= h)
    {
        int m = l + (h-l)/2;

        if(A[m] == B)
        {
            res = m;
            if(d) // find first occ
                h = m-1;
            else  // find last occ
                l = m+1;
        }
                
        else if(A[m] > B) h = m-1;
        else l = m+1;
    }

    return res;
}

/* last occurence - first occurence */

int Solution::findCount(const vector<int> &A, int B)
{
    int first = Occurance(A, B, 1);
    if(first == -1) return 0;

    return Occurance(A, B, 0) - first + 1;
}