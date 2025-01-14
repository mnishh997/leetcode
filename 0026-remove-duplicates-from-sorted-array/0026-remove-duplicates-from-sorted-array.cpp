class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        vector<int> v(201, 0);
        int i = 0;
        for(auto it: nums) {
            int idx = it + 100;
            if(v[idx] == 0) {
                v[idx] = 1;
                nums[i] = it;
                i++;
            }
        }
        return i;
    }
};