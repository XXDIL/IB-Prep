/*
        
Think of the array as this :

    [11, 13, 15, 2, 5]
    
           /|
          / |
         /  |
            |  
            | /
            |/

*/

int Solution::findMin(const vector<int>& nums)
{
    int n = nums.size();
    
    // not rotated at all
    if(nums[0] <= nums[n-1]) return nums[0];

    int l=0, h=n-1;
    while(l <= h)
    {
        int m = l + (h-l)/2;
        
        if(nums[m] > nums[m+1]) return nums[m+1];
        
        // mid = left of peak
        if(nums[m] >= nums[0]) l = m+1;
        else h = m-1;
    }
    
    return -1;
}