/*
    11     |    |           18
           |    |               
        32 |    | 34
    -------+----+-------------
           | 43 |
    -------+----+-------------
        52 |    | 54         
           |    |
           |    |              
    81     |    |           88
    
    find min(row, col) of all 4 rectangles.
*/
int Solution::solve(int A, int B)
{
    return min(B-1, A-1) + 
           min(B-1, 8-A) + 
           min(8-B, 8-A) + 
           min(8-B, A-1);
}
