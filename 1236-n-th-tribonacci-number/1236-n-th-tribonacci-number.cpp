class Solution {
public:
    int tribonacci(int n) {
        int a = 0, b = 1, c = 1;
        int ans = 0;
        if(n==0)return a;
        if(n<3)return 1;
        for(int i=3;i<n+1;i++){
            ans = a+b+c;
            a=b;b=c;c=ans;
        }
        return ans;
    }
};