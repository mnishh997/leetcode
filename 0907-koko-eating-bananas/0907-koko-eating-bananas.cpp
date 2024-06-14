class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        int n = piles.size();
        sort(piles.begin(),piles.end());
        int l = 1, r = piles[n-1];
        int ans = INT_MAX;
        while(l<=r){
            int mid = l + (r-l)/2;
            long long aux = 0;
            int j = mid;
            for (int i = 0; i < n; ++i) {
                aux+=(piles[i]/mid);
                if(piles[i]%mid!=0)aux+=1;
            }

            if(aux==h){
                ans = min(ans, mid);
                r = mid-1;
            }
            if(aux>h){
                l = mid+1;
            }
            else if(aux<h){
                r = mid -1;
            }
        }

        return min(ans, l);
    }
};