class Solution {
public:
    double findMaxAverage(vector<int>& nums, int k) {
        int res = 0;
        for(int i=0;i<k;i++){
            res+=nums[i];
        }
        int i=0, j=k;
        int temp= res;
        while(j<nums.size()){
            temp+=nums[j];
            temp-= nums[i];
            i++;
            j++;
            res = max(res, temp);
        }

        double ans = res;
        ans = ans/k;
        return ans;
    }
};