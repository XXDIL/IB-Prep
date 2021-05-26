/**
 * Definition for an interval.
 * struct Interval {
 *     int start;
 *     int end;
 *     Interval() : start(0), end(0) {}
 *     Interval(int s, int e) : start(s), end(e) {}
 * };
 */

// if the input vector is vector<vector<int>> then no need for a comparator
bool mycomp(Interval a, Interval b)
{
    return a.start < b.start;
}

vector<Interval> Solution::merge(vector<Interval>& I)
{
    int n = I.size();
    sort(I.begin(), I.end(), mycomp);
    
    Interval curr = I[0];
    vector<Interval> ans;
    
    // tipical interval merging logic (cancer)
    for(int i=1;i<n;++i)
    {
        if(curr.end >= I[i].start) 
            curr.end = max(curr.end, I[i].end);
        
        else if(curr.end < I[i].start)
        {
            ans.push_back(curr);
            curr = I[i];
        }
    }
    
    // for the last merged interval
    ans.push_back(curr);
    
    return ans;
}