int Solution::solve(int A, int B, int C, int D)
{
    vector<int> a = {A, B, C, D};
    sort(a.begin(), a.end());
    
    if(a[0] == a[1] && a[2] == a[3]) return 1;
    
    return 0;
}