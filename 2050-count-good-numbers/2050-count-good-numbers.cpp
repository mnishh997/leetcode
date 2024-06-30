class Solution {
    int M = 1e9+7;
    long long power(long long b, long long e, long long ans) {
        if(e == 0) return ans;
        if(e & 1) return power(b, e - 1, (ans * b) % M);
        else return power((b * b) % M, e / 2, ans);
    }
public:
    int countGoodNumbers(long long n) {
        // long long res = 1;
        // int f = 1;
        // for(int i=0;i<n;i++){
        //     if(f==1){
        //         res=((res%mod)*(5%mod))%mod;
        //         f=0;
        //     }
        //     else{
        //         res=((res%mod)*(4%mod))%mod;
        //         f=1;
        //     }
        // }
        // return res;
        long long temp = power(20, n/2, 1);
        if(n&1==1)return (temp*5)%M;
        return temp;
        
    }
};