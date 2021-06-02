/* tipical Bin Search */
int binSearch(vector<int> nums, int target, int l, int h)
{
    while(l <= h)
    {
        int m = l + (h-l)/2;
        
        if(nums[m] == target) return m;
        
        if(target > nums[m]) l = m+1;
        else h = m-1;
    }
    
    return -1;
}

/* find the peak BS(0, peak) then BS(peak+1, n-1) */

int Solution::search(const vector<int>& nums, int target)
{
    int n = nums.size();
    
    // no rotation
    if(nums[0] <= nums.back()) 
        return binSearch(nums, target, 0, n-1);
    
    // finding the peak
    int peak = -1;
    int l=0, h=n-1;
    while(l <= h)
    {
        int m = l + (h-l)/2;
        
        if(nums[m] > nums[m+1])
        { 
            peak = m;
            break;
        }
        
        // mid = left of peak
        if(nums[m] >= nums[0]) l = m+1;
        else h = m-1;
    }
    
    int left = binSearch(nums, target, 0, peak);
    if(left != -1) return left;
    
    return binSearch(nums, target, peak+1, n-1);
}