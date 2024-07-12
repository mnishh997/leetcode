class Solution {
    bool isvowel(char c){
        if(c=='a' || c =='e' || c == 'i' || c == 'o' || c=='u')return 1;
        return 0;
    }
public:
    int maxVowels(string s, int k) {
        int res = 0;
        for(int i=0;i<k;i++){
            if(isvowel(s[i]) == true){
                res++;
            }
        }
        int i = 0, j = k;
        int temp = res;
        while(j<s.size()){
            if(isvowel(s[i]) == true){
                temp--;
            }
            if(isvowel(s[j]))temp++;
            i++;
            j++;
            res = max(res, temp);
        }
        return res;
    }
};