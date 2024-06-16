class Solution {
public:
    long long countCompleteDayPairs(vector<int>& hours) {
        map<long long,long long> m;
        for(auto it:hours){
            m[it%24]++;
        }
        long long res = 0;
        for(auto it=m.begin();it!=m.end();it++){
            auto tt = it;
            tt++;
            for(auto jt=tt;jt!=m.end();jt++){
                if((it->first+jt->first)%24==0){
                    res+=(it->second*jt->second);
                }
            }
        }
        res+=(m[12]*(m[12]-1))/2;
        res+=(m[0]*(m[0]-1))/2;
        return res;
    }
};