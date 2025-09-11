class Solution {
public:
int rowDirec[4] = {1,-1,0,0};
int colDirec[4] = {0,0,1,-1};
    int orangesRotting(vector<vector<int>>& grid) 
    {
       queue<pair<int,int>>q;
       int fresh = 0;

       for(int i =0 ; i<grid.size(); i++)
       {
        for(int j =0 ; j<grid[0].size(); j++)
        {
            if(grid[i][j] == 1)
            {
               fresh++; 
            }
            else if(grid[i][j] == 2)
            {
                q.push({i,j});
            }
        }
       }
       if(fresh == 0)
       {
        return 0;
       }

       int timer = -1;
       while(!q.empty())
       {
          int size = q.size();
          timer++;

          for(int i =0; i<size; i++)
          {
            auto[x,y] = q.front();
            q.pop();

            for(int i =0; i<4; i++)
            {
                int newx = x+rowDirec[i];
                int newy = y+colDirec[i];

                if(newx >=0 && newx<grid.size() && newy>=0 && newy<grid[0].size() && grid[newx][newy] == 1)
                {
                    grid[newx][newy] =2;
                    fresh --;
                    q.push({newx,newy});
                }
            }

          }
       }
       if(fresh == 0)
       {
        return timer;
       }
       return -1;
    }
};