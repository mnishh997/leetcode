class Solution {

    bool h(vector<int>& candies, int d, long long k){
        long long count = 0;
        for(int i=0;i<candies.size();i++){
            count+=(candies[i]/d);
        }
        if(count>=k)return 1;
        return 0;
    }
public:
    int maximumCandies(vector<int>& candies, long long k) {
        sort(candies.begin(),candies.end());
        int n= candies.size();
        int l= 1, r = candies[n-1];
        int ans = 0;
        while(l<=r){
            int mid = l+(r-l)/2;

            if(h(candies, mid, k)){
                ans = mid;
                l = mid+1;
            }
            else r= mid-1;
        }
        return ans;
    }
};