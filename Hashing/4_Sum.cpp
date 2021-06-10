/*
    use a and b to flow like n^2 logic.

    then with c and d implement 2sumwith 2-ptr method

    the duplicate check conditions are very important,
    initially it checks for a-1 >= 0   -> a > 0
                            b-1 >= a+1 -> b > a+1

    then its trivial
*/
vector<vector<int> > Solution::fourSum(vector<int>& A, int B)
{
    sort(A.begin(), A.end());
    vector<vector<int>> ans;
    int n = A.size();
    
    for(int a=0;a<n-3;++a)
    {
        if(a>0 && A[a] == A[a-1]) continue;            // duplicate check
        
        for(int b=a+1;b<n-2;++b)
        {
            if(b>a+1 && A[b] == A[b-1]) continue;      // duplicate check
            
            // 2 sum using 2-ptr technique
            int c = b+1;
            int d = n-1;
            int T = B - A[a] - A[b];
            
            while(c < d)
            {
                int sum = A[c]+A[d];
                if(sum == T)
                {
                    while(c < d && A[c] == A[c+1]) c++;
                    while(c < d && A[d] == A[d-1]) d--;
                    
                    ans.push_back({A[a], A[b], A[c], A[d]});
                }
                
                if(sum > T) d--;
                else c++;
            }
        }
    }
    
    return ans;
}