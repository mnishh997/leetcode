class Solution {
public:
    double maxProbability(int n, vector<vector<int>>& edges, vector<double>& succProb, int start_node, int end_node) {
        vector<vector<pair<int,double>>> adj(n, vector<pair<int, double>>());
        for(int i=0;i<edges.size();i++){
            int a = edges[i][0];
            int b = edges[i][1];
            double wt = succProb[i];
            adj[a].push_back({b, wt});
            adj[b].push_back({a, wt});
        }
        priority_queue<pair<double, int>, vector<pair<double, int>>> pq;
        vector<double> dist(n, 0);

        pq.push({1, start_node});
        while(!pq.empty()){
            int node = pq.top().second;
            double prob = pq.top().first;
            pq.pop();

            for(auto it: adj[node]){
                int adjNode = it.first;
                double adjProb = it.second;
                if(dist[adjNode] < prob*adjProb){
                    dist[adjNode] = prob*adjProb;
                    pq.push({dist[adjNode], adjNode});
                }
            }
        }
        return dist[end_node];
    }
};