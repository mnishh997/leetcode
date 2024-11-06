class Solution {
public:
    bool canSortArray(vector<int>& nums) {
        int n = nums.size();
        int l = 0, r = 0;
        int prev_bits = __builtin_popcount(nums[0]);
        for(int i=1;i<n;i++) {
            if(__builtin_popcount(nums[i]) == prev_bits) {
                r++;
            }
            else {
                sort(nums.begin()+l, nums.begin() + r + 1);
                r++;
                l = r;
                prev_bits = __builtin_popcount(nums[i]);
            }
        }
        sort(nums.begin()+l, nums.begin() + r + 1);
        int hinge = nums[0];
        for(int i=1;i<n;i++) {
            if(hinge > nums[i]) {
                return 0;
            }
            hinge = nums[i];
        }
        return 1;
    }
};