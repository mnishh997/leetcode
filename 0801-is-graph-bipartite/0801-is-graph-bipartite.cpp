class Solution {
    bool bfs(int k, vector<vector<int>>& graph, vector<int>& color, vector<bool>& vis){
        queue<pair<int,int>> q;
        q.push({k, -1});
        vis[k] = 1;
        color[k] = 1;
        // 1 2
        while(!q.empty()){
            int node = q.front().first;
            int par = q.front().second;

            q.pop();

            for(auto it:  graph[node]){
                if(vis[it]==true){
                    if(it == par){
                        continue;
                    }
                    else{
                        if(color[it]==color[par]){
                            continue;
                        }
                        else{
                            return false;
                        }
                    }
                }
                else{
                    if(color[node] == 1)color[it] = 2;
                    else color[it] = 1;

                    vis[it]=true;
                    q.push({it, node});
                }
            }
        }
        return true;
    }
public:
    bool isBipartite(vector<vector<int>>& graph) {
        int n = graph.size();
        vector<int> color(n, 0);
        vector<bool> vis(n, 0);

        for(int i=0;i<n;i++){
            if(vis[i] == false){
                if(bfs(i, graph, color, vis) == false)return false;
            }
        }
        return true;
    }
};