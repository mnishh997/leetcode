class Solution {
public:
    int jump(vector<int>& nums) {
        int n = nums.size();
        if(nums.size()<=1)return 0;

        for(int i=1;i<nums.size();i++){
            nums[i]=max(nums[i]+i, nums[i-1]);
        }

        int i =0, jumps = 0;
        while(i<n-1){
            jumps++;
            i=nums[i];
        }
        return jumps;
    }
};