class Solution {
public:
    int numIdenticalPairs(vector<int>& nums) {
        map<int,int> m;

        for(auto it: nums){
            m[it]++;

        }
        int res  = 0;
        for(auto it: m){
            res+=(it.second*(it.second-1))/2;
        }return res;
    }
};