class Solution {
    void f(vector<int>& candidates, int target, int i, vector<int> temp,vector<vector<int>>& res){
        if(target == 0){
            res.push_back(temp);
            return;
        }
        if(i==candidates.size())return;
        
        if(target<0)return;
        
        f(candidates, target, i+1,temp, res);
        temp.push_back(candidates[i]);
        f(candidates, target-candidates[i], i, temp, res);
    }
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        // using recursion
        vector<int> temp;
        vector<vector<int>> res;
        f(candidates, target, 0, temp,res);
        return res;
    }
};