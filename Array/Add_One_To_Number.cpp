vector<int> Solution::plusOne(vector<int>& A) 
{   
    // removing leading 0's : [0, 0, 1, 2, 3] --> [1, 2, 3]
    auto it = A.begin();
    while(*it == 0 && A.size() > 1) A.erase(it);
    
    int n = A.size();
    bool carry = 1; // assume carry is there
    
    // tackeling the chain of carries
    int i = n-1;
    while(carry == 1 && i>=0)
    {
        A[i] += 1;
        if(A[i] == 10)
        {
            carry = 1;
            A[i] = 0;
        }
        else carry = 0;
        --i;
    }
    
    // last carry needs a new index
    if(carry == 1) A.insert(A.begin(), 1);
    
    return A;
}
