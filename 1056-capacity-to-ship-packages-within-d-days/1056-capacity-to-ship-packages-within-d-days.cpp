class Solution {
public:
    int shipWithinDays(vector<int>& nums, int days) {
        int sum = 0;
        int maxi = INT_MIN;
        for(auto it: nums){
            sum+=it;
            maxi = max(maxi, it);
        }

        int l = maxi, r = sum;
        int ans = INT_MAX;
        while(l<=r){
            int mid = l+ (r-l)/2;
            int temp = 0;
            int cnt = 0;
            for(int i=0;i<nums.size();i++){
                if(cnt+nums[i]<=mid){
                    cnt+=nums[i];
                }
                else{
                    temp++;
                    cnt = nums[i];
                }
            }
            temp+=1;
            if(temp<=days){
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