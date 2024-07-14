class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        int res = 0;
        unordered_map<int, int> m;
        for(auto it: tasks){
            m[it-'A']++;
        }
        priority_queue<int> pq;//max_heap(iske top par max value hogi)
        for(auto it: m){
            pq.push(it.second);
        }
        queue<pair<int,int>> q;

        while(!pq.empty() || !q.empty()){
            res++;
            if(pq.empty() == false){
                int freq = pq.top();
                pq.pop();
                int time = res+n;
                freq = freq-1;
                if(freq>0)q.push({freq, time});
            }
            if(!q.empty()){
                while(res == q.front().second){
                    int freq = q.front().first;
                    q.pop();
                    pq.push(freq);
                }
            }
        }
        return res;
    }   
};