// tipical LPS Array Generation Code
vector<int> LPS_Array(string s)
{
    int n = s.length();
    vector<int> LPS(n);

    int j = 0, i = 1;
    while (i < n)
    {
        if (s[i] == s[j])
        {
            LPS[i] = j+1;
            i++,j++;
        }
        else
        {
            if (j != 0)
                j = LPS[j-1];
            else
                i++;
        }
    }
    
    return LPS;
}

/*
    The main point is that we need to generate the
    longest palingrome that ends at n-1.
    
    if s = "abede" then the longest palin = "ede", therefore
    we would need to add n - len(palin) to get the answer.
    
    one way is to merge the 2 strings rev(s)+"|"+s.
    
    Try it out, Quite a good question.
*/
int Solution::solve(string A)
{
    int n = A.size();
    
    string rA = A;
    reverse(rA.begin(), rA.end());
    
    vector<int> lps = LPS_Array(rA+"|"+A);
    
    return n-lps.back();
}