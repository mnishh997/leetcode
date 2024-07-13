class Solution {
public:
    vector<vector<int>> findDifference(vector<int>& nums1, vector<int>& nums2) {
        set<int> s;
        for(auto it: nums1)s.insert(it);

        for(auto it: nums2){
            auto pos = s.find(it);
            if(pos == s.end())continue;
            else s.erase(it);
        }

        vector<int> a1(s.begin(), s.end());
        s.clear();
        for(auto it: nums2)s.insert(it);

        for(auto it: nums1){
            auto pos = s.find(it);
            if(pos == s.end())continue;
            else s.erase(it);
        }
        vector<int> a2(s.begin(), s.end());
        vector<vector<int>> ans;
        ans.push_back(a1);
        ans.push_back(a2);
        return ans;
    }
};