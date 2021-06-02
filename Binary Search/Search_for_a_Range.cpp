int occurence(vector<int> nums, int target, bool dia)
{
    int n = nums.size();
    int l=0, h=n-1, res = -1;
    
    while(l <= h)
    {
        int m = l + (h-l)/2;
        if(nums[m] == target)
        {
            res = m;
            
            if(dia) h = m-1;
            else l = m+1;
        }
        
        else if(nums[m] > target) h = m-1;
        else l = m+1;
    }
    
    return res;
}

/* Ditto of Count_Element_Occurence.cpp */

vector<int> Solution::searchRange(const vector<int>& nums, int target)
{
    return {occurence(nums, target, 1), occurence(nums, target, 0)};
}