/*
    normally I would come up with the heap solution(O(Nlogk))
    but its good to learn new DS's, deque can be used(O(N)).

    memorize the solution TBH : https://www.youtube.com/watch?v=LiSdD3ljCIE
*/

vector<int> Solution::slidingMaximum(const vector<int> &A, int k)
{
    int n = A.size();
    deque<pair<int, int>> DQ;
    
    // dealing with 1st window where we dont need to print max.
    for(int i=0;i<k-1;++i)
    {
        while(!DQ.empty() && DQ.back().first < A[i]) DQ.pop_back();
        DQ.push_back({A[i], i});
    }
    
    vector<int> ans;
    for(int i=k-1;i<n;++i)
    {     
        // making sure the dedue is in descending order
        while(!DQ.empty() && DQ.back().first < A[i]) DQ.pop_back();
        DQ.push_back({A[i], i});
        
        // inserting the max only if it lies in the wondow else pop
        while(DQ.front().second <= i-k) DQ.pop_front();
        ans.push_back(DQ.front().first);
    }
    
    return ans;
}