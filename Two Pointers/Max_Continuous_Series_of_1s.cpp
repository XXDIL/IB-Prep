/* Similar to Maximum_Ones_After_Modification.cpp */
vector<int> Solution::maxone(vector<int> &A, int k)
{
    int n = A.size();
    int i=0, j=0;
    int ans = 0;
    int c0 = 0;
    int maxj = -1, maxi = -1;
    
    while(j < n)
    {
        if(A[j] == 0)
        {
            if(c0 < k) c0++;
            else
            {
                if(j-i > ans)
                {
                    ans = j-i;
                    maxi = i;
                    maxj = j;
                }

                while(A[i] != 0) i++;
                i++;
            }
        }
        j++;
    }

    if(j-i > ans)
    {
        maxi = i;
        maxj = j;
    }

    vector<int> ind;
    for(int a=maxi;a<maxj;++a)
        ind.push_back(a);
    
    return ind;
}