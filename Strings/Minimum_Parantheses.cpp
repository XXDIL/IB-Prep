/*
    you will need to variables

    think about the case : ")))("
*/
int Solution::solve(string A)
{
    int lb = 0, rb = 0;
    for(int i=0;i<A.size();++i)
    {
        if(A[i] == '(') lb++;
        else
        {
            if(lb == 0) rb++;
            else lb--;
        }
    }
    
    return rb+lb;
}