/* 
    The main trick is to view the list in descending order.

    where i < j < k
    and A[i] >= A[j] >= A[k]

    Therefore :
        A[i] + A[j] > A[k]    thanks to the 
        A[i] + A[k] > A[j]    array being sorted

        A[j] + A[k] > A[i]    need to ensure


    now it becomes a normal 3Sum problem.
*/

int Solution::nTriang(vector<int>& nums)
{
    int n = nums.size();
    sort(nums.begin(), nums.end(), greater<int>());
    long long c = 0;
    
    for(int i=0;i<n;++i)
    {
        int j = i+1;
        int k = n-1;
        
        while(j < k)
        {
            if(nums[j]+nums[k] > nums[i])
            {
                c = (c+k-j) % 1000000007;
                j++;
            }
            else k--;
        }
    }
    
    return c;
}