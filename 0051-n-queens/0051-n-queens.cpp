class Solution {
public:
bool check(int n , vector<string>&board , int i , int j)
{
    // Check For Upper Left Side
    int row = i , col = j;
    while(row > -1 && col >-1)
    {
        if(board[row][col] == 'Q')
        {
            return 0;
        }
        row -- , col --;
    }
    // Check For Upper Right Side
    row =i , col =j;
    while(row >-1 && col < n)
    {
        if(board[row][col] == 'Q')
        {
            return 0;
        }
        row-- , col++;

    }
    return 1;

}
void find(int row , int n , vector<vector<string>>&ans ,vector<string>&board ,vector<bool>&column)
{
    // Base Condition
    if(row == n)
    {
        ans.push_back(board);
        return;
    }
    //Put Queen at any N Position
    for(int j=0; j<n; j++)
    {
        if(column[j] == false && check(n,board,row,j))
        {
            column[j] = 1;
            board[row][j] = 'Q';

            find(row+1 , n ,ans,board,column);
            column[j] =0;
            board[row][j] = '.';
        }
        
    }
}
    vector<vector<string>> solveNQueens(int n) 
    {
        vector<vector<string>>ans;
        vector<string>Board(n);
        for(int i =0; i<n; i++)
        {
            for(int j=0; j<n; j++)
            {
                Board[i].push_back('.');
            }
        }
        vector<bool>column(n,0);
        find(0,n,ans,Board,column);
        return ans;
    }
};