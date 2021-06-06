/* I prefer doing it without a stack, to sace space */
int Solution::solve(string A)
{
    int c = 0;
    for(auto i : A)
    {
        if(i == '(') c++;
        else c--;
        
        if(c < 0) return 0;
    }
    
    if(c != 0) return 0;
    
    return 1;
}