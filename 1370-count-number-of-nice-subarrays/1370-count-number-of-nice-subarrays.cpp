class Solution {
public:
    int numberOfSubarrays(vector<int>& nums, int k) {
        int n = nums.size();
        vector<int> v(n+1, 0);
        v[0]=1;
        int ans=0, temp = 0;
        for(auto it: nums){
            temp+=it&1;
            if(temp-k>=0){
                ans+=v[temp-k];
            }
            v[temp]++;
        }
        return ans;
    }
};