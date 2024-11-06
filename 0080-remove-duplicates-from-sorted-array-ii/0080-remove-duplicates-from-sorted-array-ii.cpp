class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int res = nums.size();
        map<int, int> m;
        for(auto& it: nums) {
            if(m[it]!=2) {
                m[it] ++;
            }
            else {
                it = INT_MAX;
                res--;
            }
        }
        sort(nums.begin(), nums.end());
        return res;
    }
};