/*
    It doesnt matter what dates they arrive at, 
    the most important is arrive and depart.

    1 and 0 are used 
        1) to show arrive and depart
        2) as well as act as a comparator (if the A and D are are the same date then depart should happen 1st)
*/
bool Solution::hotel(vector<int> &A, vector<int> &B, int C)
{
    vector<pair<int, int>> temp;
    int n = A.size();
    for(int i=0;i<n;++i)
    {
        temp.push_back({A[i], 1});
        temp.push_back({B[i], 0});
    }
    sort(temp.begin(), temp.end());

    int room=0, maxroom=0;
    for(int i=0;i<2*n;++i)
    {
        if(temp[i].second == 1) // arrival
        {
            room++;
            maxroom = max(maxroom, room);
        }
        else
            room--;
    }

    return C >= maxroom;
}