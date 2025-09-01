class Solution {
public:
    void DFS(int node, int parent, vector<bool>& visit, vector<int>& low,
             vector<int>& disc, vector<vector<int>>& bridges, int &count,
             vector<vector<int>>&AdjList) 
            {
                disc[node] = low[node] = count;
                visit[node] =1;

                for(auto it : AdjList[node])
                {
                    if(parent == it)
                    {
                        continue;
                    }
                    else if(visit[it] == true)
                    {
                        low[node] = min(low[it] , low[node]);
                    }
                    else
                    {
                        count++;
                        DFS(it, node, visit,low,disc,bridges,count,AdjList);
                        // Check If the Bridge Exist 
                        if(low[it] > disc[node])
                        {
                            vector<int>temp;
                            temp.push_back(node);
                            temp.push_back(it);
                            bridges.push_back(temp);
                        }
                        low[node] = min(low[node] , low[it]);

                    }
                }
            }
    vector<vector<int>> criticalConnections(int n, vector<vector<int>>& connections) 
    {
        vector<vector<int>> AdjList(n);
        vector<vector<int>> bridges;
        vector<int> disc(n); // Discovery Time 
        vector<int> low(n);  // Low 
        vector<bool> visit(n, 0);
        int count = 0;
        for (auto it : connections) 
        {
            AdjList[it[0]].push_back(it[1]);
            AdjList[it[1]].push_back(it[0]);
        }
        DFS(0, -1, visit, low, disc, bridges, count, AdjList);
        return bridges;
    }
};