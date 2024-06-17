class Solution {
    void f(vector<int>& nums, vector<vector<int>>& res, set<vector<int>>& s, vector<int> temp, int i){
        if(i==nums.size()){
            sort(temp.begin(),temp.end());
            if(s.find(temp)==s.end()){
                s.insert(temp);
                res.push_back(temp);
            }
            return;
        }

        f(nums, res, s, temp, i+1);
        temp.push_back(nums[i]);
        f(nums, res, s, temp, i+1);

    }
public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        set<vector<int>> s;
        vector<vector<int>> res;
        vector<int> temp;
        f(nums, res, s, temp, 0);
        return res;
    }
};