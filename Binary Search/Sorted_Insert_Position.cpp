/* find the index, where nums[m] < target */
int Solution::searchInsert(vector<int>& nums, int target)
{
    int n = nums.size();
    int l=0, h=n-1;
    
    while(l <= h)
    {
        int m = l + (h-l)/2;
        
        if(nums[m] >= target) h = m-1;
        else l = m+1;
    }
    
    return l;
}