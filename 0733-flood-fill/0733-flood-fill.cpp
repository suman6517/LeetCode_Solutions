class Solution {
public:
void dfs(int iniColor , int color, vector<vector<int>>&image , vector<vector<int>>&ans,
          int deltaRow[] , int deltaCol[], int row, int col)
{
    ans[row][col] = color;
    int rowSize = image.size();
    int colSize = image[0].size();

    for(int i=0; i<4; i++)
    {
        int nrow = row+deltaRow[i];
        int ncol = col+deltaCol[i];
        if(nrow >=0 && nrow < rowSize && ncol >=0 && ncol<colSize && image[nrow][ncol]==iniColour && 
           ans[nrow][ncol] != iniColor)
           {
            dfs(iniColor, color, image, ans, deltaRow, deltaCol, nrow, ncol);
           }
    }
}

    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) 
    {
        int iniColor = imeage[sr][sc];
        vector<vector<int>>ans = image;
        int deltaRow[]={-1,0,+1,0};
        int deltaCol[]={0,+1,0,-1};
        dfs(iniColor , color ,image ,ans,deltaRow ,deltaCol,sr,sc);
        return ans;

    }
};