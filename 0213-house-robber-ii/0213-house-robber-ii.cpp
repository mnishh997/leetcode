class Solution {
public:
    int f(vector<int>& v) {
        int n = v.size();
        if(n == 1) return v[0];
        if(n == 2)return max(v[1], v[0]);
        int a = max(v[1], v[0]), b = v[0], c = 0;
        for(int i=2;i<n;i++) {
            c = max(a, b+v[i]);
            b = a, a = c;
        }
        return max(a, b);
    }

    int rob(vector<int>& nums) {
        int n = nums.size();
        if(n == 1) return nums[0];
        if(n == 2) return max(nums[0], nums[1]);
        vector<int> v;
        for(int i=0;i<n-1;i++) {
            v.push_back(nums[i]);
        }
        int maxi = f(v);
        for(int i=1;i<n;i++) {
            v[i-1] = nums[i];
        }
        maxi = max(maxi, f(v));
        return maxi;
    }
};