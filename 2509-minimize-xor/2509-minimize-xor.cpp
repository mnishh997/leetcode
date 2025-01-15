class Solution {
public:
    int minimizeXor(int num1, int num2) {
        int count = __builtin_popcount(num2);
        int res = 0;
        for(int i=1;i<=32;i++) {
            if(num1&(1<<(32-i)) && count>0) {
                res+=(1<<(32-i));count--;
            }
        }
        if(count>0) {
            for(int i=0;i<32;i++) {
                if(((res>>i)&1) == 0 && count>0) {
                    res+=(1<<i);
                    count--;
                }
            }
        }
        return res;
    }
};