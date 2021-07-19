/*
    Method 1 : (using 2 maps)
        1) you store B into a map BM
        2) then keep updating AM accordingly

    but you dont need 2 maps

    Method 2 : (using 1 map)
        1) you store B into a map BM
        2) we maintain a counter = B.size()
        3) we let the BM go till negative [case : A="bba" B="ab"]
        4) update count 
            4.1) increase count if u move i and M[A[i]] > 0
            4.2) decrease count if u move j and M[A[j]] > 0
*/
string Solution::minWindow(string A, string B)
{
    int m=A.size(), n=B.size();
    if(n > m) return "";
    
    // fill BM with frequency
    unordered_map<char, int> BM;
    for(auto i : B) BM[i]++;

    // so we dont have to do sunstr everytime
    pair<int, int> ans = {0, INT_MAX};
    int i=0, j=0;
    while(j <= m)
    {
        // this is if an answer is possible
        if(n == 0)
        {
            // found a smaller ans
            if(j-i < ans.second)
                ans = {i, j-i};

            BM[A[i]]++;
            if(BM[A[i]] > 0)
                n++;
            
            i++;
        }
        // we still nee to find the ans
        else
        {
            if(BM[A[j]] > 0)
                n--;
            BM[A[j]]--;
            j++;
        }
    }
    
    // no match [case : A="a" B="b"]
    if(ans.second == INT_MAX)
        return "";
    
    return A.substr(ans.first, ans.second);
}