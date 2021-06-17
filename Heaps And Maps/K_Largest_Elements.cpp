/*
    Cheaky Quick Select
*/
vector<int> Solution::solve(vector<int>& nums, int k)
{
    nth_element(nums.begin(), nums.end()-k, nums.end());
    
    return vector<int>(nums.end()-k, nums.end());
}