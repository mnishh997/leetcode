class Solution {
public:
    long long minOperations(vector<int>& nums) {
        int n = nums.size();
        long long maxi = nums[0];

        vector<int> temp;
        for(int i=0;i<n;i++) {
            maxi = max(maxi, 1LL*nums[i]);
            temp.push_back(maxi - nums[i]);
        }
        long long res = temp.back();

        for(int i=n-2;i>=0;i--) {
            if(temp[i] <= temp[i+1]) {
                continue;
            }
            else {
                res += (temp[i] - temp[i+1]);
            }
        }
        return res;
    }
};

// 0 0 23 13 21