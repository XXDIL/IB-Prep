/*
    There can be a max of 1 odd frequent char.
*/
int Solution::solve(string A)
{
    unordered_map<char, int> M;
    for(auto i : A)
        M[i]++;
    
    // count of mismatches (ie odd frequent chars)
    int mis = 0;
    for(auto i : M)
        if(i.second & 1)
            mis++;
    
    return mis/2 == 0 ? 1 : 0;
}