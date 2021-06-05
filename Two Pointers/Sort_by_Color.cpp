/* 
    Keep 
        left ptr at 0     (for storing 0's)
        right ptr at n-1  (for storing 2's)

    notice that we dont increment i if its swapped for a 2

*/

void Solution::sortColors(vector<int> &A)
{
    int n = A.size();
    int i=0, l=0, r=n-1;
    while(i<r+1)
    {
        if(A[i] == 0)
        {
            swap(A[i], A[l]);
            l++, i++;
        }
        
        else if(A[i] == 2)
        {
            swap(A[i], A[r]);
            r--;
        }
        else ++i;
    }
}