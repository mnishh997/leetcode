class Solution {
public:
    bool canPartition(vector<int>& nums) {
        int sum = 0;
        int n = nums.size();
        for(auto it:nums)sum+=it;

        if((sum&1)==1)return false;
        int k = sum/2;
        vector<vector<bool>> dp(n,vector<bool>(k+1,0));
        for(int i=0;i<n;i++){
            dp[i][0]=1;
        }
        if(nums[0]<=k)dp[0][nums[0]]=1;
        for(int i=1;i<n;i++){
            for(int j =1;j<=k;j++){
                dp[i][j]=dp[i-1][j];
                if(j>=nums[i])dp[i][j]=dp[i][j]|dp[i-1][j-nums[i]];
            }
        }
        return dp[n-1][k];
    }
};