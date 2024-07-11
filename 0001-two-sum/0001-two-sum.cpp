class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<pair<int, int>> help;
        for(int i=0;i<nums.size();i++){
            help.push_back({nums[i], i});
        }
        sort(help.begin(), help.end());

        int i= 0, j = nums.size()-1;
        while(i<j){
            if(help[i].first + help[j].first == target)break;
            else if(help[i].first + help[j].first > target)j--;
            else i++;
        }
        return {help[i].second, help[j].second};
    }
};