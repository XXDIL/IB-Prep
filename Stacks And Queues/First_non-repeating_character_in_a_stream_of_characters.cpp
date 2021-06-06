/*
    maintain a 
        Queue(to maintain the order) 
        map(to count the frequency)
*/

string Solution::solve(string A)
{
    unordered_map<char, int> H;
    queue<char> Q;
    string newA = "";
    
    for(auto i : A)
    {
        if(H[i] == 0) Q.push(i);
        else if(!Q.empty() && i == Q.front())
        {
            Q.pop();
            while(!Q.empty() && H[Q.front()] != 1) Q.pop();
        }
        
        H[i]++;
        newA += Q.empty() ? '#' : Q.front();
    }
    
    return newA;
}