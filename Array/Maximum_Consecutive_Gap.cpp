/* 
    Pure Logic of Bucketing:

    Explanation : https://leetcode.com/problems/maximum-gap/discuss/1241681/JavaPython-Bucket-Idea-with-Picture-Clean-and-Concise-O(N)
*/
int Solution::maximumGap(const vector<int> &A)
{
    int n = A.size();
    int MIN = A[0], MAX = A[0];
    for(int i=1;i<n;++i)
    {
        MIN = min(MIN, A[i]);
        MAX = max(MAX, A[i]);
    }
    
    if(MAX==MIN) return 0;
    int BucketSize = ceil(((double)MAX-MIN)/(n-1));
    
    int MAXvec[n], MINvec[n];
    for(int i=0;i<n;++i)
    {
        MAXvec[i] = -1;
        MINvec[i] = INT_MAX;
    }
    
    for(int i=0;i<n;++i)
    {
        int j = (A[i] - MIN)/BucketSize;
                    
        MINvec[j] = min(MINvec[j], A[i]);
        MAXvec[j] = max(MAXvec[j], A[i]);
    }
    
    int i=1, j=0;
    int ans = 0;
    while(i<n && j<n)
    {
        if(MINvec[i] == INT_MAX && MAXvec[j] == -1) i++, j++;
        else if(MINvec[i] == INT_MAX) i++;
        else if(MAXvec[j] == -1) j++;
        else
        {
            ans = max(ans, MINvec[i] - MAXvec[j]);
            i++, j++;
        }
    }
    
    return ans;
}