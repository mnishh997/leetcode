class Solution {
public:
    int maxProfitAssignment(vector<int>& d, vector<int>& profit, vector<int>& worker) {
        int sz = *max_element(d.begin(),d.end());
        vector<int> h(sz+1,0);
        for(int i=0;i<d.size();i++){
            h[d[i]]=max(h[d[i]],profit[i]);
        }
        for(int i=1;i<sz+1;i++){
            h[i]=max(h[i],h[i-1]);
        }

        int res = 0;
        for(int it: worker){
            if(it>sz)res+=h[sz];
            else{
                res+=h[it];
            }
        }
        return res;
    }
};