class Solution {
    bool h(vector<int>& q, int k, int n){
        int cnt = 0;
        for(int i=0;i<q.size();i++){
            cnt+=(q[i]/k);
            if(q[i]%k>0)cnt++;
        }
        if(cnt<=n)return true;
        return false;
    }
public:
    int minimizedMaximum(int n, vector<int>& quantities) {
        sort(quantities.begin(),quantities.end());
        int N= quantities.size();
        int l = 1, r = quantities[N-1];
        int ans = 1;
        while(l<=r){
            int mid = l+(r-l)/2;
            if(h(quantities, mid, n)){
                ans = mid;
                r = mid -1;
            }
            else{
                l = mid+1;
            }
        }
        return ans;
    }
};