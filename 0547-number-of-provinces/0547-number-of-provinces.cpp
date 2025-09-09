class Solution {
public:
void DFS(int node , vector<bool>&visit, vector<int>AdjList[])
{
    visit[node] = 1;
    for(auto it: AdjList[node])
    {
        if(!visit[it])
        {
            DFS(it,visit,AdjList);
        }
    }
}
    int findCircleNum(vector<vector<int>>& isConnected) 
    {
        int rowSize = isConnected.size();
        int colSize = isConnected[0].size();

        vector<int>AdjList[rowSize];

        for(int i =0; i<rowSize; i++)
        {
            for(int j=0; j<colSize; j++)
            {
                if(isConnected[i][j] == 1 && i!=j)
                {
                    AdjList[i].push_back(j);
                    AdjList[j].push_back(i);
                }
            }
        }
        vector<bool>visit(rowSize,0);
        int Provinces =0;

        for(int i =0; i < rowSize; i++)
        {
            if(!visit[i])
            {
                Provinces++;
                DFS(i ,visit,AdjList);
            }
        }
        return Provinces;
    }
};