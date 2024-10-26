class Solution {
public:
void bfs(int row, int col, vector<vector<int>>&visit , vector<vector<char>>&grid , int rowSize, int colSize)
{
    visit[row][col] =1;
    queue<pair<int,int>>qu;
    qu.push({row , col});

    while(!qu.empty())
    {
        int row = qu.front().first;
        int col =qu.front().second;
        qu.pop();

        //Traverse In The Neighbours
        // for (int deltaRow =-1; deltaRow<=1; deltaRow++)
        // {
        //     for(int deltaCol= -1; deltaCol<=1; deltaCol++)
        //     {
        //         int nrow= row+deltaRow;
        //         int ncol = col+deltaCol;
        //         if(nrow >=0 && nrow < rowSize && ncol>=0 && ncol< colSize
        //          && grid[nrow][ncol]=='1' && !visit[nrow][ncol])
        //          {
        //             visit[nrow][ncol]=1;
        //             qu.push({nrow,ncol});
        //          }

        //     }

            int dRow[] = {-1, 1, 0, 0};
            int dCol[] = {0, 0, -1, 1};
            for (int i = 0; i < 4; i++) 
            {
                int nrow = row + dRow[i];
                int ncol = col + dCol[i];
                if (nrow >= 0 && nrow < rowSize && ncol >= 0 && ncol < colSize
                    && grid[nrow][ncol] == '1' && !visit[nrow][ncol]) {
                    visit[nrow][ncol] = 1;
                    qu.push({nrow, ncol});
                }
            }
        }
}
    int numIslands(vector<vector<char>>& grid) 
    {
        int isLand =0;
        int rowSize = grid.size();
        int colSize = grid[0].size();
        vector<vector<int>>visit(rowSize ,vector<int>(colSize, 0));

        for(int row = 0; row<rowSize ; row++)
        {
            for(int col =0; col<colSize ; col++)
            {
                if(!visit[row][col] && grid[row][col] =='1')
                {
                    isLand++;
                    bfs(row , col, visit, grid , rowSize, colSize);
                }
            }
        }
        return isLand;
    }
};