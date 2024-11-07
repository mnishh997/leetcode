class Solution {
public:
    int largestCombination(vector<int>& candidates) {
        vector<int> v(32, 0);
        int res = 0;
        for(int i=0;i<candidates.size();i++) {
            for(int j=0;j<=31;j++) {
                v[j] += (candidates[i]>>j)%2;
                res = max(res, v[j]);
            }
        }
        return res;
    }
};