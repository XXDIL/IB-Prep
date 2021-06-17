/*
    Push everytinh into a heap.
    pop B times and insert top-1.
*/
int Solution::solve(vector<int> &A, int B) 
{
    priority_queue<int> maxh(A.begin(), A.end());
    
    int ans = 0;
    while(B--)
    {
        int top = maxh.top();
        ans += top;
        
        top--;
        maxh.pop();
        maxh.push(top);
    }
    
    return ans;
}