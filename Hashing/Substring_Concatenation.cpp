/*
    i goes from 0 to s.length()

    for every i we create a string "word" that is of size ws.
    if this word is found in the map 
        then we start to check for the other words too.
        else just skip

    "sliding window logic"
*/
vector<int> Solution::findSubstring(string s, const vector<string>& words)
{
    int n = s.size();
    int ws = words[0].size();
    int wc = words.size();
    
    unordered_map<string, int> M;
    for(auto word : words)
        M[word]++;
    
    vector<int> ans;
    for(int i=0;i<(n+1-wc*ws);++i)
    {
        string word = s.substr(i, ws);
        
        if(M.find(word) != M.end())
        {
            unordered_map<string, int> tempM = M;
            int j = i;
            while(wc && j+ws <= n && tempM[word] > 0)
            {
                tempM[word]--;
                
                wc--;
                j+=ws;
                word = s.substr(j, ws);
            }

            if(wc == 0)
                ans.push_back(i);
                
            wc = words.size();
        }
    }
    
    return ans;
}