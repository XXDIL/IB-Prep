/* 
    Try finding the minimium difference between sum and T

    the reason we have minDiff = T - sum and not minDiff = sum - T is because
    at the end I am returning T - minDiff. 

    so if I took minDiff = sum - T, i would get 
        T - (sum - T) = 2T - sum (!= sum)

    if i wanted to make minDiff = sum - T then i would have to 
        return minDiff + T
*/

int Solution::threeSumClosest(vector<int>& nums, int T)
{
    int n = nums.size();
    sort(nums.begin(), nums.end());
    
    int minDiff = INT_MAX;
    
    for(int i=0;i<n-2;++i)
    {
        int j = i+1;
        int k = n-1;
        
        while(j < k)
        {
            int sum =  nums[i] + nums[j] + nums[k];
            
            if(sum == T) return T; // for speed
            
            if(abs(sum - T) < abs(minDiff)) // main if condition
                minDiff = T - sum;
            
            // obvious steps
            if(sum > T) k--;
            else j++;
        }
    }
    
    /*  T - minDiff => T - (T - sum) => sum  */
    return T-minDiff;
}