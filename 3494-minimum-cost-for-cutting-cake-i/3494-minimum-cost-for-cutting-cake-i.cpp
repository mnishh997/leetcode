class Solution {
public:
    long long minimumCost(int m, int n, vector<int>& h, vector<int>& v) {
        sort(h.begin(), h.end(), greater<int>());
        sort(v.begin(), v.end(), greater<int>());

        int i=0, j=0;
        int a = 1, b = 1;
        long long res = 0;
        while(i<h.size() && j<v.size()){
            if(h[i]>v[j]){
                res+=h[i]*a;
                b++;
                i++;
            }
            else{
                res+=v[j]*b;
                a++;
                j++;
            }
        }
        while(i<h.size()){
            res+=h[i]*a;
            i++;
        }
        while(j<v.size()){
            res+=v[j]*b;
            j++;
        }
        return res;
    }
};