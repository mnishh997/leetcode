class Solution {
public:
    int missingNumber(vector<int>& nums) {
       int a = 0;
       int n = nums.size();
       for(int i=0;i<=n;i++) {
            a = a^i;
       } 
       int b = 0;
       for(int i=0;i<n;i++) {
            b = b^nums[i];
       }
       return a^b;
    }
};