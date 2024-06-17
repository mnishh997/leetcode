class Solution {
public:
    bool judgeSquareSum(int c) {
        int n= 1<<16;
        vector<long long> v(n+1,0);
        for(long long i=0;i<=n;i++){
            v[i]=i*i;
        }

        int i = 0, j = n;
        while(i<=j){
            if(v[i]+v[j]==(long long)c){
                return true;
            }
            else if(v[i]+v[j]<(long long)c){
                i++;
            }
            else if(v[i]+v[j]>(long long)c){
                j--;
            }
        }
        return false;

    }
};