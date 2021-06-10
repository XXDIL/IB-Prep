/*
    use 3 9x9 booleam matrix to keep track of the numbers .

    3*(i/3) + j/3, once you think about it it makes sense.


    k ----> 0 0 0 1 1 1 2 2 2
            0 0 0 1 1 1 2 2 2
            0 0 0 1 1 1 2 2 2
            3 3 3 4 4 4 5 5 5
            3 3 3 4 4 4 5 5 5
            3 3 3 4 4 4 5 5 5
            6 6 6 7 7 7 8 8 8
            6 6 6 7 7 7 8 8 8
            6 6 6 7 7 7 8 8 8

*/

int Solution::isValidSudoku(const vector<string> &board)
{
    vector<vector<bool>> R(9, vector<bool>(9));
    vector<vector<bool>> C(9, vector<bool>(9));
    vector<vector<bool>> box(9, vector<bool>(9));
    
    for(int i=0;i<9;++i)
    {
        for(int j=0;j<9;++j)
        {
            if(board[i][j] != '.')
            {
                int k = 3*(i/3) + j/3; // genius alert
                int num = board[i][j] - '0' - 1;
                    
                if(R[i][num] || C[j][num] || box[k][num]) return 0;

                R[i][num] = C[j][num] = box[k][num] = 1;
            }
        }
    }
    
    return 1;
}