class Solution {
public:
    int smallestDivisor(vector<int>& nums, int threshold) {
        int maxi = INT_MIN;
        for(auto it: nums){
            maxi = max(maxi, it);
        }

        int l = 1, r = maxi;
        int ans = INT_MAX;
        while(l<=r){
            int mid = l + (r-l)/2;

            int sum = 0;
            for(int i = 0;i<nums.size();i++){
                sum+=(nums[i]/mid);
                if(nums[i]%mid != 0)sum+=1;


            }
            if(sum<=threshold){
                ans = min(ans, mid);
                r = mid-1;
            }
            else{
                l = mid+1;
            }
        }
        return ans;
    }
};