class Solution {
    int M = 1e9 + 7;
public:
    int xorAfterQueries(vector<int>& nums, vector<vector<int>>& queries) {
        for(auto it: queries) {
            long long l = it[0], r = it[1], k = it[2], v= it[3];
            for(int i=l;i<=r;i+=k) {
                long long a = nums[i];
                a = a* v;
                a = a%M;
                nums[i] = a;
            }
        }
        int res = 0;
        for(int i=0;i<nums.size();i++) {
            res = res^nums[i];
        }
        return res;
    }
};