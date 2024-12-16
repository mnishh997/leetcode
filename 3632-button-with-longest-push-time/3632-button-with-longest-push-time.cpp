class Solution {
public:
    int buttonWithLongestTime(vector<vector<int>>& events) {
        int res = events[0][0];int diff = events[0][1];
        for(int i=1;i<events.size();i++) {
            if(diff<events[i][1] - events[i-1][1]) {
                res = events[i][0]; diff = events[i][1] - events[i-1][1];
            }
            else if(diff == events[i][1] - events[i-1][1]) {
                res = min(res, events[i][0]);
            }
        }
        return res;
    }
};