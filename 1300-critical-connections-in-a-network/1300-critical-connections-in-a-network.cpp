class Solution {
    int timer = 1;
    void dfs(int node, int par, vector<bool>& vis, vector<int> adj[], int tin[], int low[], vector<vector<int>>& bridges){
        vis[node] = 1;
        tin[node] = low[node] = timer;
        timer++;
        for(auto it: adj[node]){
            if(it == par)continue;
            else{
                if(vis[it] == true){
                    low[node] = min(low[node], low[it]);
                }
                else{
                    dfs(it, node, vis, adj, tin, low, bridges);
                    low[node] = min(low[node], low[it]);
                    if(low[it]>tin[node]){
                        bridges.push_back({it, node});
                    }
                }
            }
        }

    }
public:
    vector<vector<int>> criticalConnections(int n, vector<vector<int>>& connections) {
        vector<int> adj[n];
        for(int i=0;i<connections.size();i++){
            adj[connections[i][0]].push_back(connections[i][1]);
            adj[connections[i][1]].push_back(connections[i][0]);
        }
        vector<bool> vis(n, 0);
        int tin[n], low[n];
        vector<vector<int>> bridges;
        dfs(0, -1, vis, adj, tin, low, bridges);
        return bridges;
    }
};