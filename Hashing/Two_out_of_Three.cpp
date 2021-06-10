/*
    use key as the element ans the set to store the arrays its in
        1 - A
        2 - B
        3 - C
*/
vector<int> Solution::solve(vector<int> &A, vector<int> &B, vector<int> &C)
{
    map<int, unordered_set<int>> M;
    for(auto i : A) M[i].insert(1);
    for(auto i : B) M[i].insert(2);
    for(auto i : C) M[i].insert(3);
 
    vector<int> ans;
    for(auto i : M)
    {
        if(i.second.size() >= 2)
            ans.push_back(i.first);
    }
    
    return ans;
}