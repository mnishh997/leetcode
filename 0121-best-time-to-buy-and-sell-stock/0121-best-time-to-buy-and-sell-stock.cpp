class Solution {
public:
    int maxProfit(vector<int>& v) {
        int mintn= INT_MAX;
        int maxtn= 0;
        int res= 0;
        for(int i=0;i<v.size();i++){
            //mitn = min(mitn, prices[i]);
            //matn = max(matn, prices[i]);
            /*if(maxtn<v[i]){
                if(mintn!=INT_MAX){
                    maxtn = v[i];
                    res = max(res, maxtn-mintn);
                    
                }
                else{
                    mintn= maxtn= v[i];
                }
            }
            else if(mintn>v[i]){
                maxtn= 0;
                mintn = v[i];
            }*/
            if(mintn>v[i]){
                maxtn= 0;
                mintn = v[i];
            }
            else if(maxtn<v[i]){
                maxtn = v[i];
                res = max(res, maxtn-mintn);

            }
        }
        return res;
    }
};