/* 
    skip all the occurances of !B,
    if B is found then switch B to !B
    repeat 
*/
int Solution::bulbs(vector<int> &A)
{
    int n = A.size();
    int i=0, B=0, ans=0;
    while(i<n)
    {
        while(i<n && A[i]!=B) ++i;

        if(i==n) break; // [1,1,1,1,1] case

        ans++;
        B = 1-B;
        ++i;
    }

    return ans;
}