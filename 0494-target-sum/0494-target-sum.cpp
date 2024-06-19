class Solution {
public:
    int findTargetSumWays(vector<int>& nums, int target) {
        int sum = 0;
        for(int it: nums)sum+=it;

        if(sum<target)return 0;
        if(((sum-target)&1)==1)return 0;

        int k = (sum-target)/2;

        vector<vector<int>> dp(nums.size(), vector<int>(k+1, 0));

        for(int i=0;i<nums.size();i++){
            dp[i][0]=1;
        }
        if(nums[0]<=k)dp[0][nums[0]]=1;
        if(nums[0]==0)dp[0][0]=2;

        for(int i=1;i<nums.size();i++){
            for(int j=0;j<=k;j++){
                dp[i][j]=dp[i-1][j];
                if(j>=nums[i])dp[i][j]+=dp[i-1][j-nums[i]];
            }
        }
        return dp[nums.size()-1][k];
    }
};