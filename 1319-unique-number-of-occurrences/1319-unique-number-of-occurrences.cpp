class Solution {
public:
    bool uniqueOccurrences(vector<int>& arr) {
        unordered_map<int,int> m;
        for(auto it:arr){
            m[it] ++;
        }
        int sz = m.size();
        unordered_set<int> s;
        for(auto it: m){
            s.insert(it.second);
        }
        if(s.size() == sz)return 1;
        return 0;
    }
};