/**
 * Definition for an interval.
 * struct Interval {
 *     int start;
 *     int end;
 *     Interval() : start(0), end(0) {}
 *     Interval(int s, int e) : start(s), end(e) {}
 * };
 */

vector<Interval> Solution::insert(vector<Interval>& I, Interval N)
{
    int n = I.size();
    
    // if N has to be added to the front of I
    if(n == 0 || N.end < I[0].start)
    {
        I.insert(I.begin(), N);
        return I;
    }
    
    // if N has to be appended to the end of I
    if(N.start > I[n-1].end)
    {
        I.push_back(N);
        return I;
    }
    
    // findin the left interval index
    int l = 0;
    while(I[l].end < N.start)
        l++;
    l--;
    
    // findin the right interval index
    int r = 0;
    while(r < n && I[r].start <= N.end)
        r++;
                    
    vector<Interval> ans;
    
    // insert the left part
    if(l != -1)
        ans.insert(ans.end(), I.begin(), I.begin()+l+1);
    
    //insert the merged interval
    ans.push_back({min(I[l+1].start, N.start), max(I[r-1].end, N.end)});
    
    //insert the right part
    if(r != n)
        ans.insert(ans.end(), I.begin()+r, I.end());
            
    return ans;
}