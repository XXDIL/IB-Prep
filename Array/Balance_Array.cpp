/* 
    keep track of previous odd_i sum and even_i sum (as these wont be flipped)
    but the right side will flip, ie se and so nee to be flipped each time an element has been removed.
 */
int Solution::solve(vector<int> &A)
{
    int n = A.size();
    int se, so, pree, preo;
    se = so = pree = preo = 0;

    for(int i=0;i<n;++i)
        if(i&1) so += A[i];
        else se += A[i];

    int c = 0;
    for(int i=0;i<n;++i)
    {
        if(i&1)
        {
            so -= A[i];
            if(pree+so == preo+se)
                c++;
            preo += A[i];
        }
        else
        {
            se -= A[i];
            if(pree+so == preo+se)
                c++;
            pree += A[i];
        }
    }

    return c;
}