class Solution {
public:
    int rob(vector<int>& nums) {
        int n = nums.size();
        if(n == 1)return nums[0];
        if(n == 2) return max(nums[0], nums[1]);
        int a = max(nums[0], nums[1]), b = nums[0], c = 0;

        for(int i = 2;i<n;i++) {
            c = max(a, b+nums[i]);
            b = a, a = c;
        }
        return max(a, b);
    }
};