/*
    lots of scope of improvement in time and space
    complexity.

    Inittially your mind may go towards using a set to 
    store unique values.

    But you can take care of duplicates by skipping 
    them while changing j and k values.

    if target = 12
    [1,2,3,5,5,5,5,5,6] -> we can skip those 5's 
    because only the 1st occurance is unique.

    and for ith index we just skip that index if it
    has occured just before.

    long long is used to accomodate for INT_MIN <= A[i] <= INT_MAX
*/

vector<vector<int>> Solution::threeSum(vector<int>& nums)
{
    sort(nums.begin(), nums.end());
    int n = nums.size();
    vector<vector<int>> ans;
    
    for(int i=0;i<n-2;++i)
    {
        if(i>0 && i<n && nums[i] == nums[i-1]) continue;
        
        int j = i+1;
        int k = n-1;
        
        long long T = -(long long)nums[i];
        while(j < k)
        {
            long long sum = (long long)nums[j] + (long long)nums[k];
            if(sum == T)
            {
                ans.push_back({nums[i], nums[j], nums[k]});
                while(j < k && nums[j] == nums[j+1]) ++j;
                while(j < k && nums[k] == nums[k-1]) --k;
            }
            
            if(sum > T) k--;
            else j++;
        }
    }
    
    return ans;
}