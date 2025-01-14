class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int curr = 0, res = 0;
        for(int i=0;i<nums.size();i++) {
            if(nums[i] == 1) {
                curr+=1;
            }
            else {
                res = max(curr, res);
                curr = 0;
            }
        }
        res = max(curr, res);
        return res;
    }
};