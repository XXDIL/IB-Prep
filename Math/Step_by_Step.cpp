/* https://www.youtube.com/watch?v=K8yXBn4cCQs */
int Solution::solve(int target)
{
    // doesnt matter if its negative (symmetry)
    target = abs(target);
    int ans = 0;
    int distance = 0;
    
    // initially try to cross the target
    while(target > distance)
    {
        ans++;
        distance += ans;
    }
    
    // until the diffference is odd
    while((distance-target)%2)
    {
        ans++;
        distance += ans;
    }
    
    return ans;
}