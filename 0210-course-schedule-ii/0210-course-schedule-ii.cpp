class Solution {
public:
    vector<int> findOrder(int n, vector<vector<int>>& pre) {
        vector<vector<int>> adj(n, vector<int>());
        vector<int> indegree(n, 0);
        for(int i=0;i<pre.size();i++)
        {
            adj[pre[i][1]].push_back(pre[i][0]);
            indegree[pre[i][0]]++;
        }
        queue<int> q;
        for(int i=0;i<n;i++)
        {
            if(indegree[i]==0)q.push(i);
        }
        vector<int> topo;
        while(!q.empty())
        {
            int node = q.front();
            q.pop();
            topo.push_back(node);
            for(auto it: adj[node])
            {
                indegree[it]--;
                if(indegree[it]==0)q.push(it);
            }
        }
        if(topo.size()==n)return topo;
        return {};
    }
};