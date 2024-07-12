class Solution {
public:
    int pivotIndex(vector<int>& nums) {
        int sum = 0;
        for(auto it: nums)sum+=it;

        int l = 0;
        int i = 0;
        for(auto it: nums){
            if(l == sum - l - it)return i;
            l+=it;
            i++;
        }
        return -1;
    }
};