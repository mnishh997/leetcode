class Solution {
public:
    vector<int> arrayRankTransform(vector<int>& arr) {
        map<int, int> m; 
        for(auto it: arr) {
            m[it] = 1e9;
        }
        int rank = 1;
        for(auto&it:m) {
            it.second = rank;
            rank++;
        }
        for(auto&it:arr) {
            it = m[it];
        }
        return arr;
    }
};