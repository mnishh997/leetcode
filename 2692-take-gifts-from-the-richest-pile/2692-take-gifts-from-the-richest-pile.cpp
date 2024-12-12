class Solution {
public:
    long long pickGifts(vector<int>& gifts, int k) {
        priority_queue<int> pq;
        for(auto it: gifts) pq.push(it);
        while(k--) {
            int gift = pq.top();
            pq.pop();
            int temp = sqrt(gift);
            pq.push(temp);
        }
        long long int res = 0;
        while(!pq.empty()) {
            res+=pq.top();
            pq.pop();
        }
        return res;
    }
};