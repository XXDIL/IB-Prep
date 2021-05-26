int Solution::coverPoints(vector<int> &A, vector<int> &B) 
{
    // Think about Chess Board Distance
    int x,y,sum=0;
    for(int i =1; i<A.size();i++)
    {
        x=abs(A[i]-A[i-1]);
        y=abs(B[i]-B[i-1]);
        sum+=max(x,y);
    }
    return sum;
}
