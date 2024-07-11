class Solution {
public:
    string gcdOfStrings(string s, string t) {
        int n = s.size();
        int m = t.size();
        int aux = __gcd(n,m);
        string temp = "";
        for(int i=0;i<aux;i++){
            temp+=t[i];
        }
        string ss ="", tt = "";
        int nn = n/aux, mm = m/aux;
        for(int i=0;i<nn;i++){
            ss+=temp;
        }
        for(int i=0;i<mm;i++){
            tt+=temp;
        }
        if(s==ss && t==tt){
            return temp;
        }
        temp = "";
        return temp;
    }
};