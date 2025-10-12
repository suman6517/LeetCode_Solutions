class Solution {
public: 
bool check(int i ,vector<vector<char>>& board , int curRow, int curCol)
{
    char c = '0' + i;

    // Check at same col
    for(int k =0 ; k<9; k++)
    {
        if(board[curRow][k] == c)
        {
            return 0;
        }
    }
    // check for same row 
    for(int j=0 ; j<9; j++)
    {
        if(board[j][curCol] == c)
        {
            return 0;
        }
    }

    // same box
    int row = curRow/3*3;
    int col = curCol/3*3;
    for(int a=0; a<3; a++)
    {
        for(int b=0; b<3; b++)
        {
            if(board[a+row] [b+col] == c)
            {
                return 0;
            }
        }
    }
    return 1;
}
bool find(int row , int col ,vector<vector<char>>& board)
{
    // Base condition 
    if(row == 9)
    {
        return 1;
    }
    if(col == 9)
    {
        return find(row+1 , 0 , board);
    }
    if(board[row][col] != '.')
    {
        return find(row,col+1,board);
    }
    for(int i =1; i<10; i++)
    {
        if(check(i , board , row ,col))
        {
            board[row][col] = '0'+i;
            if(find(row , col+1, board))
            {
                return 1;
            }
            board[row][col] ='.';
        }
    }
    return 0;

}
    void solveSudoku(vector<vector<char>>& board) 
    {
        find(0,0,board);
    }
};