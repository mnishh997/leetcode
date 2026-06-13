class Solution {
public:
    bool consecutiveSetBits(int n) {
        int cnt = 0;
        int curr = 0;
        while(n) {
            curr+=(n&1);
            if((n&1) == 0) {
                curr = 0;
            }
            if(curr == 2)cnt++;
            n>>=1;

            if(curr>2)return false;
            if(cnt>2)return false;
        }
        return (cnt == 1);
    }
};