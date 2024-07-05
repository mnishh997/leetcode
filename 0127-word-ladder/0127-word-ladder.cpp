class Solution {
    bool matching(string a, string b){
        int temp = 0;
        for(int i=0;i<a.size();i++){
            if(a[i]!=b[i])temp++;
        }
        if(temp==1)return true;
        return 0;
    }
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        int n = wordList.size();
        bool f = 0;
        for(int i=0;i<n;i++){
            if(wordList[i]==endWord){
                f = 1;
            }
        }
        if(f==0)return 0;
        vector<vector<pair<string, int>>> adj(n, vector<pair<string, int>>());
        for(int i=0;i<n;i++){
            for(int j = i+1; j < n; j++){
                if(matching(wordList[i], wordList[j])==true){
                    adj[i].push_back({wordList[j], j});
                    adj[j].push_back({wordList[i], i});
                }
            }
        }

        bool h = 0;
        int ind = n;
        for(int i=0;i<n;i++){
            if(wordList[i] == beginWord){
                h = 1;
                ind = i;
            }
        }
        if(h == 0){
            vector<pair<string, int>> temp;
            for(int i=0;i<n;i++){
                if(matching(beginWord, wordList[i]) == true){
                    temp.push_back({wordList[i], i});
                    // adj[i].push_back(temp);
                }
            }
            adj.push_back(temp);
        }

        queue<pair<string, int>> q;
        int ans = 0;
        q.push({beginWord, ind});
        vector<bool> vis(adj.size(), false);
        vis[ind]=true;
        while(!q.empty()){
            int k = q.size();
            while(k--){
                string s = q.front().first;
                int index = q.front().second;
                if(s == endWord)return ans+1;
                q.pop();
                for(auto it: adj[index]){
                    if(vis[it.second]==false){
                        q.push(it);
                        vis[it.second] = true;
                    }
                }
            }
            ans++;
        }
        return 0;
    }
};