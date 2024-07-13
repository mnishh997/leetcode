class Solution {
public:
    bool closeStrings(string word1, string word2) {
        unordered_map<char,int> m1, m2;
        unordered_set<char> s;
        multiset<int> t , y;
        
        for(auto it: word1){
            m1[it] ++;
            s.insert(it);
        }
        for(auto it: m1){
            t.insert(it.second);
        }
        int sz = s.size(), szz = t.size();
        for(auto it: word2){
            m2[it]++;
            s.insert(it);
        }
        if(s.size()>sz)return false;
        for(auto it: m2){
            y.insert(it.second);
        }
        if(y.size()!=t.size())return 0;
        auto it = t.begin();
        auto jt = y.begin();
        while(it!=t.end() && jt!=y.end()){
            if(*it != *jt)return 0;
            it++;
            jt++;
        }
        return 1;
    }
};