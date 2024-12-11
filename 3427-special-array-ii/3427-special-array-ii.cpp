class Solution {
public:
    vector<bool> isArraySpecial(vector<int>& nums, vector<vector<int>>& queries) {
        vector<int> v(nums.size(), 0);
        int sum = 0;
        for(int i=0;i<nums.size();i++) {
            bool l = 1, r = 1;
            if(i-1>=0){
                if(nums[i-1]%2 == nums[i]%2) l = false;
            }
            if(i+1<nums.size()) {
                if(nums[i+1]%2 == nums[i]%2) r = false;
            }
            if(l && r) {
                v[i] = sum;
            }
            else {
                if(l == false) {
                    sum+=1;
                    v[i] = sum;
                }
                if(r == false) {
                    sum+=2;
                    v[i] = sum;
                }
            }
        }
        vector<bool> ans;
        for(auto it: queries) {
            int from = it[0], to = it[1];
            if(v[from] == v[to] || v[from]+2 == v[to]) {
                ans.push_back(true);
            }
            else ans.push_back(false);
        }
        return ans;

    }
};