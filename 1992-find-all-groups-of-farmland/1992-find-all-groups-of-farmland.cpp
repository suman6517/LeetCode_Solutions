class Solution {
public:
    int n,m;
    int dx[4]={-1,0,1,0};
    int dy[4]={0,1,0,-1};
    void dfs(int i,int j,vector<vector<int>> &vis,vector<vector<int>> &land,int &l,int &d){
        vis[i][j]=1;
        for(int k=0;k<4;k++){
            int r=dx[k]+i,c=dy[k]+j;
            if(r>=0 && r<n && c>=0 && c<m && vis[r][c]==-1 && land[r][c]==1)
             { 
                   l=max(l,r);
                   d=max(d,c);
                   dfs(r,c,vis,land,l,d); 
             }
         }

    }
    vector<vector<int>> findFarmland(vector<vector<int>>& land) {
        n=land.size(),m=land[0].size();
        vector<vector<int>> vis(n,vector<int>(m,-1)),ans;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(land[i][j]==1 && vis[i][j]==-1){
                   int r=i,c=j;
                   dfs(i,j,vis,land,r,c);
                   ans.push_back({i,j,r,c});
                }
            }
        }
        return ans;
    }
};