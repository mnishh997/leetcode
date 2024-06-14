class Solution {
public:
    int minDays(vector<int>& f, int m, int k) {
        int mini = INT_MAX, maxi = INT_MIN;
        int n = f.size();
        long long v = (long long)m*k;
        if(v>n)return -1;
        for(int i=0;i<f.size();i++){
            mini = min(mini, f[i]);
            maxi = max(maxi, f[i]);
        }

        long long l = mini, r = maxi;
        int ans = INT_MAX;
        
        while(l<=r){
            long long cnt = 0;
            long long temp = 0;
            long long mid = l + (r-l)/2;
            for(int i=0;i<n;i++){
                if(f[i]<=mid){
                    cnt++;
                }
                else{
                    temp+=(cnt/k);
                    cnt = 0;
                }
            }
            temp+=(cnt/k);
            if(temp>=m){
                ans = min((long long)ans, mid);
                r = mid-1;
            }
            else{
                l = mid+1;
            }
        }
        return ans;
    }
};