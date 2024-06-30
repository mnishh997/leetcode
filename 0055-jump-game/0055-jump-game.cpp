class Solution {
public:
    bool canJump(vector<int>& nums) {
        int maxi = nums[0];
        int n = nums.size();
        for(int i=1;i<n;i++){
            if(i<=maxi){
                maxi = max(maxi, i+nums[i]);
            }
            else{
                return 0;
            }
        }
        return 1;
    }
};