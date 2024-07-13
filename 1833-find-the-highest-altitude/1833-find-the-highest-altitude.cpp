class Solution {
public:
    int largestAltitude(vector<int>& gain) {
        int temp = 0;int res = 0;
        for(auto it: gain){
            temp+=it;
            res = max(res, temp);
        }
        return res;
    }
};