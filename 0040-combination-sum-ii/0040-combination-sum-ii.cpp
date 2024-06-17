#include <vector>
#include <algorithm>

using namespace std;

class Solution {
    void f(vector<int>& candidates, int target, vector<vector<int>>& res, int start, vector<int> temp) {
        if (target == 0) {
            res.push_back(temp);
            return;
        }
        
        for (int i = start; i < candidates.size(); ++i) {
            // Skip duplicates
            if (i > start && candidates[i] == candidates[i - 1]) continue;
            
            // Break early if the number is greater than the target
            if (candidates[i] > target) break;
            
            temp.push_back(candidates[i]);
            f(candidates, target - candidates[i], res, i + 1, temp);
            temp.pop_back();
        }
    }
    
public:
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        vector<vector<int>> res;
        vector<int> temp;
        sort(candidates.begin(), candidates.end());
        f(candidates, target, res, 0, temp);
        return res;
    }
};

