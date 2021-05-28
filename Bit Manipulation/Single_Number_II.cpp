int Solution::singleNumber(const vector<int> &A)
{
    vector<int> nums = A;
    int n = nums.size();
    if(n == 1) return nums[0];
    
    sort(nums.begin(), nums.end());
    
    // [2,3,3,3,4,4,4] case
    if(nums[0] != nums[1]) 
        return nums[0];
    
    int ans;
    for(int i=0;i<n-1;i+=3)
        if(nums[i] != nums[i+1])
            return nums[i];
    
    // [] case
    return nums[n-1];
}


/*
    NO NEED TO DO THIS METHOD (TOO HARD)

    int Solution::singleNumber(const vector<int> &A)
    {
        int ones = 0, twos = 0;
        int n = A.size();
        
        for(int i=0; i<n;i++)
        {
            ones = (ones ^ A[i]) & ~twos;
            twos = (twos ^ A[i]) & ~ones;
        }
        return ones;
    }

*/