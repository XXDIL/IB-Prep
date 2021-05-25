void Solution::setZeroes(vector<vector<int>>& matrix)
{
    /*
        At a specific (i,j) index the 2nd qudrant is always visited. 
        ie (0,0) to (i,j) will be all visited.
        
        So we could just mark the rows and cols that need to be
        filled with 0, by marking the 1st row and column.
    */
    
    int m = matrix.size();
    int n = matrix[0].size();
    
    bool row = 0, col = 0;
    
    // marking the ros and cols
    for(int i=0;i<m;++i)
        for(int j=0;j<n;++j)
            if(matrix[i][j] == 0)
            {
                // what if we need to make the 1st row and col also 0
                if(i == 0) row = 1;
                if(j == 0) col = 1;
                
                matrix[i][0] = 0;
                matrix[0][j] = 0;
            }
    
    // filling the rows and cols with 0
    for(int i=1;i<m;++i)
        for(int j=1;j<n;++j)
            if(matrix[i][0] == 0 || matrix[0][j] == 0)
                matrix[i][j] = 0;
    
    // filling col 1 with 0
    if(col)
        for(int i=0;i<m;++i)
            matrix[i][0] = 0;
            
    // filling row 1 with 0 
    if(row)
        for(int j=0;j<n;++j)
            matrix[0][j] = 0;
}
