class Solution {
public:
    long long findScore(vector<int>& nums) {
        long long int res = 0;
        priority_queue<pair<int,int>, vector<pair<int,int> >, greater<pair<int, int> > > pq;
        map<int, int> m; // index , ele

        for(int i=0;i<nums.size();i++) {
            m[i] = nums[i];
            pq.push({nums[i], i});
        }

        while(!pq.empty()) {
            int num = pq.top().first;
            int index = pq.top().second;
            pq.pop();
            if(m[index] == 0) {
                continue;
            }
            res+=num;
            if(index-1>=0) m[index-1] = 0;
            if(index+1<nums.size()) m[index+1] = 0;

            m[index] = 0;
        }
        

        return res;
    }
};