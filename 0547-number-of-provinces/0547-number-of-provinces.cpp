class Solution {
public:
void dfs(int node ,vector<int>adj[], vector<int>&visit)
{
    visit[node] =1;
    for(auto it: adj[node])
    {
        if(!visit[it])
        {
            dfs(it , adj, visit);
        }
    }
}
    int findCircleNum(vector<vector<int>>& isConnected) 
    {
        int vertex = isConnected.size();
         vector<int>adj[vertex];
         
        vector<int>visit(vertex,0);
        for(int i=0; i<vertex; i++)
        {
            for(int j=0; j<vertex; j++)
            {
                if(isConnected[i][j] == 1 && i!=j)
                {
                    adj[i].push_back(j);
                    adj[j].push_back(i);
                }
            }
        }
        int  province=0;

        for(int i=0; i<vertex; i++)
        {
            if(!visit[i])
            {
                 province++;
                dfs(i , adj, visit);
            }
        }
        return  province;


    }
};