class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        vector<int> temp;
        for(auto it: nums) {
            if(it != val) temp.push_back(it);
        }
        nums = temp;
        return temp.size();
    }
};