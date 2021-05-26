vector<int> Solution::repeatedNumber(const vector<int>& nums)
{
    /*
        purely math
        
        find 
            - Actual sum
            - Expected sum (formula)
            - Actual sum of squares
            - Expected sum of squares (formula_
    */
    int n = nums.size();
    
    int A = 0;
    int E = (n*(n+1))/2;
    
    int A2 = 0;
    int E2 = (E*(2*n+1))/3;
    
    for(int i : nums)
    {
        A += i;
        A2 += i*i;
    }
    
    /*
        X^2 - Y^2 = (X+Y)(X-Y)
        
        using this we can fins the 2 variables
    */
    
    int diff = A-E;
    int diff2 = A2-E2;
    
    int sum = diff2/diff;
    
    return {(sum+diff)/2, (sum-diff)/2};
}
