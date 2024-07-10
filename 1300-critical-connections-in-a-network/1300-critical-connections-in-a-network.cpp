class Solution {
    int timer = 1;
    void dfs(int node, int par, int tin[], int low[], vector<vector<int>>& res, vector<vector<int>>& adj, vector<bool>& vis){
        vis[node] =true;
        tin[node] = low[node] = timer;
        timer++;
        for(int i=0;i<adj[node].size();i++){
            if(adj[node][i] == par)continue;
            else{
                if(vis[adj[node][i]] == true){
                    low[node] = min(low[node], low[adj[node][i]]);
                }
                else{
                    dfs(adj[node][i], node, tin, low, res, adj, vis);
                    low[node] = min(low[node], low[adj[node][i]]);
                    if(low[adj[node][i]]>tin[node]){
                        res.push_back({node, adj[node][i]});
                    }
                }
            }
        }
    }
public:
    vector<vector<int>> criticalConnections(int n, vector<vector<int>>& connections) {
        // make the graph
        vector<vector<int>> adj(n, vector<int>());
        for(int i=0;i<connections.size();i++){
            adj[connections[i][0]].push_back(connections[i][1]);
            adj[connections[i][1]].push_back(connections[i][0]);
        }
        // now I have the graph
        int tin[n], low[n];
        vector<vector<int>> res;
        vector<bool> vis(n, false);
        dfs(0, -1, tin, low, res, adj, vis);
        return res;
    }
};