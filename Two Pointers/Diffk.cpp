// similar to Pair_With_Given_Difference.cpp

int Solution::diffPossible(vector<int> &nums, int k)
{
    sort(nums.begin(), nums.end());
    int n = nums.size();
    int i=0, j=1;
    // int c = 0;
    
    while(i<n && j<n)
    {
        int diff = nums[j] - nums[i];
        
        if(i!=j && diff == k)
        {
            
            return 1;
            /*
                for counting distinct pairs

                c++;
                while(j < n-1 && nums[j]==nums[j+1]) ++j;
                while(i < n-1 && nums[i]==nums[i+1]) ++i;
            */
        }
        
        if(diff < k) j++;
        else i++;
    }
    
    return 0;
}