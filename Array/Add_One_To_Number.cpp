vector<int> Solution::plusOne(vector<int>& A) 
{   
    int n = A.size();

    // removing leading 0's
    int i = 0;
    while(i<n-1 && A[i] == 0) i++;
    A = vector<int>(A.begin()+i, A.end());

    int carry = 1;
    n = A.size();
    for(int i=n-1;i>=0;--i)
    {
        int sum = A[i]+carry;

        A[i] = sum%10;
        carry = sum/10;
    }

    if(carry)
        A.insert(A.begin(), 1);
    
    return A;
}
