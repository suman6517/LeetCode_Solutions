class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) 
    {
        int rowSize = grid.size();
        int colSize = grid[0].size();
        queue<pair<pair<int,int> ,int>>q;
        vector<vector<int>>visit;

        for(int i =0; i<rowSize; i++)
        {
            for(int j=0; j<colSize; j++)
            {
                if(grid[i][j]==2)
                {
                    q.push({ {i,j} ,0});
                    visit[i][j] = 2;
                }
                else
                {
                    visit[i][j] =0;
                }
            }
        }
        int time = 0;
        int deltaRow[]={-1,0,+1,0};
        int deltaCol[]={0,+1,0,-1};
        while(!q.empty())
        {
            int row =q.front().first.first;
            int col = q.front().first.second;
            int timer = q.front().second;
            time = max(timer, time);

            for(int i =0; i<4; i++)
            {
                int nrow = row+deltaRow[i];
                int ncol = col+deltaCol[i];
                if(nrow >=0 && nrow < rowSize && ncol >=0 && ncol<colSize && grid[nrow][ncol]==1 && 
                   visit[nrow][ncol] != 2)
                {
                    q.push({{nrow , ncol}, timer+1});
                    visit[nrow][ncol] = 2;
                }
            }
        }
        for(int i=0; i<rowSize; i++)
        {
            for(int j =0; j<colSize ; j++)
            {
                if(vis[i][j] !=2 && grid[i][j]==1)
                {
                    return -1;
                }
            }
        }
        return time;
    }
};