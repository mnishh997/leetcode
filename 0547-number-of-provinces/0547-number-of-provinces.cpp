class Solution {
    void bfs(vector<int>& vis, vector<vector<int>>& adj, int node){
        vis[node]=1;
        queue<int> q;
        q.push(node);
        while(!q.empty()){
            int n = q.front();
            q.pop();
            for(auto it: adj[n]){
                if(vis[it]==0){
                    q.push(it);
                    vis[it]=1;
                }
            }
        }
    }
public:
    int findCircleNum(vector<vector<int>>& isConnected) {
        int res = 0;
        int n = isConnected.size();
        // first of all i need an adjacency list
        vector<vector<int>> adj(n,vector<int>());
        for(int i=0;i<n;i++){
            for(int j=i+1;j<n;j++){
                if(isConnected[i][j]==1){
                    adj[i].push_back(j);
                    adj[j].push_back(i);
                }
            }
        }
        // now i have adjacency list

        vector<int> vis(n,0);
        for(int i=0;i<n;i++){
            if(vis[i]==false){
                bfs(vis, adj, i);
                res++;
            }
        }
        return res;
    }
};