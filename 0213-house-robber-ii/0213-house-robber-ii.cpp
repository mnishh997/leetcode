class Solution {
    void f(vector<int>&temp, vector<int>& dp){
        dp[0]=temp[0];
        if(temp.size()==1)return;
        dp[1]=max(temp[0],temp[1]);
        for(int i=2;i<temp.size();i++){
            dp[i]=max(dp[i-1],dp[i-2]+temp[i]);
        }
        return;
    }
public:
    int rob(vector<int>& nums) {
        int n = nums.size();
        if(n==1)return nums[0];
        vector<int> temp;
        for(int i=0;i<nums.size()-1;i++){
            temp.push_back(nums[i]);
        }

        vector<int> dp1(n-1,0);
        f(temp, dp1);
        for(int i=1;i<n;i++){
            temp[i-1]=nums[i];
        }
        vector<int> dp2(n-1,0);
        f(temp, dp2);
        return max(dp1[n-2],dp2[n-2]);
    }
};