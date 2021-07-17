/*
    Observation : there will be atmost 2 ME's

    1) so maintain 2 counters.
    2) the initialization doesnt matter as long as their counts are 0.
    3) you need to verify both th 1st and 2nd ME;

    Source : https://leetcode.com/problems/majority-element-ii/discuss/63520/Boyer-Moore-Majority-Vote-algorithm-and-my-elaboration
*/
int Solution::repeatedNumber(const vector<int>& A)
{
    int ME[2][2]; // val, count
    ME[0][0] = ME[0][1] = ME[1][0] = ME[1][1] = 0;
    
    for(auto i : A)
    {
        if(ME[0][0] == i)
            ME[0][1]++;
        else if(ME[1][0] == i)
            ME[1][1]++;
        else if(ME[0][1] == 0)
            ME[0][0] = i, ME[0][1] = 1;
        else if(ME[1][1] == 0)
            ME[1][0] = i, ME[1][1] = 1;
        else
            ME[0][1]--, ME[1][1]--;
    }

    // verify the 1st and 2nd ME's
    ME[1][1] = ME[0][1] = 0;
    for(auto i : A)
    {
        if(ME[0][0] == i)
            ME[0][1]++;
        else if(ME[1][0] == i)
            ME[1][1]++;
    }
    
    if(ME[0][1] > A.size()/3)
        return ME[0][0];
    if(ME[1][1] > A.size()/3)
        return ME[1][0];

    return -1;
}
