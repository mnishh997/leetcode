class Solution {
public:
    int maximumBeauty(vector<int>& nums, int k) {
        vector<int> v(100002, 0);
        for(auto it: nums) {
            v[max(it-k, 0)] += 1;
            v[min(it+k+1, 100001)] += -1;
        }
        int preSum = 0;
        int maxi = 1;
        for(auto it: v) {
            preSum += it;
            maxi = max(maxi, preSum);
        }
        return maxi;

       
    }
};