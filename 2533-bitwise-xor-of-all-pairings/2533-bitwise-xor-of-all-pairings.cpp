class Solution {
public:
    int xorAllNums(vector<int>& nums1, vector<int>& nums2) {
        int n1 = nums1.size(), n2 = nums2.size();
        int res = 0;
        if(n1%2 == 1) {
            for(auto it: nums2) {
                res = res^it;
            }
        }
        if(n2%2 == 1) {
            for(auto it: nums1) {
                res = res^it;
            }
        }
        return res;
    }
};