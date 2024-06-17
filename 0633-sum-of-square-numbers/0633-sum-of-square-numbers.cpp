class Solution {
public:
    bool judgeSquareSum(int c) {
        unordered_map<int,int> m;
        
        for (long long d = 2; d * d <= c; d++) {
            while (c % d == 0) {
                if(d%4==3)m[d]++;
                c /= d;
            }
        }
        if (c > 1){
            if(c%4==3)m[c]++;
        }
        for(auto it: m){
            if(it.second%2!=0)return false;
        }
        return true;
            
    }
};