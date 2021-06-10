/*
    get frequency of each element

    traverse A to find the 1st element with count > 1
*/
int Solution::solve(vector<int> &A)
{
    unordered_map<int, int> M;
    for(auto i : A)
        M[i]++;

    for(auto i : A)
        if(M[i] > 1)
            return i;

    return -1;
}