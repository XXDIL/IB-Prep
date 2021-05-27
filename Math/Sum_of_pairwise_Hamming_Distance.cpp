/*
    eg [2, 4, 6]

    2   010
    4   100
    6   110

    consider them column wise

    number of different bits will be (num_0's * num_1's)
*/

#define MOD 1000000007

int Solution::hammingDistance(const vector<int>& nums)
{
    long n = nums.size();
    long sum = 0;
    
    for(int j=0;j<32;++j)
    {
        int ones = 0;
        for(int i=0;i<n;++i)
            if(nums[i]&(1<<j)) 
                ones++;
                
        sum += (ones*(n-ones))%MOD;
    }
    
    return (2*sum)%MOD;
}