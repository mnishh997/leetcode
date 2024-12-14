class Solution {
public:
    long long continuousSubarrays(vector<int>& nums) {
        long long int res = 0;
        int n = nums.size();
        map<int, int> m;
        int l = 0, r = 0;
        
        while(r<n) {
            m[nums[r]]++;

            while(m.rbegin()->first - m.begin()->first > 2) {
                m[nums[l]] --;
                if(m[nums[l]] == 0) {
                    m.erase(nums[l]);
                }
                l++;
            }

            res += r-l + 1;
            r++;
        }
        return res;
    }
};