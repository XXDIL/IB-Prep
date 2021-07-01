/* 
    dont use a function and it will pass, 
    use median of all the x's available

    A = "...xxx....xxxx..."
                   ^ median x

    and bring the left and right x's to it  
*/
int Solution::seats(string A)
{
    vector<int> posx;
    int n = A.size();

    // store the indices of 'x'
    for(int i=0;i<n;++i)
        if(A[i] == 'x')
            posx.push_back(i);

    // in the case of A = "...."
    if(posx.size() == 0) return 0;

    // long long due to IB 
    long long ans = 0;
    int x = posx.size()/2;

    // left search
    for(int i=x-1, j=posx[x]-1; i>=0; --i, --j)
        ans = (ans + j - posx[i])%10000003;

    // right search
    for(int i=x+1, j=posx[x]+1; i<posx.size(); ++i, ++j)
        ans = (ans + posx[i] - j)%10000003;

    return ans%10000003;
}