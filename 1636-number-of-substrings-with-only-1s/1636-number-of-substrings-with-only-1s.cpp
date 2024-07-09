class Solution {
public:
int M = 1e9 + 7;
    int numSub(string s) {
        long long res = 0;
        long long temp = 0;
        for(int i=0;i<s.size();i++){
            if(s[i] == '1'){
                temp++;
                
            }
            else{
                res+=((temp%M*(temp%M+1)%M)/2)%M;
                temp = 0;
            }
        }
        res+= ((temp%M*(temp%M+1)%M)/2)%M;
        return res;
    }
};