class Solution {
    bool h(vector<int>& arr, int d, int m){
        int n = arr.size();
        int count = 1;
        int last = arr[0];
        for(int i=1;i<n;i++){
            if(arr[i]-last >= d){
                count++;
                last = arr[i];
            }
        }
        if(count>=m){
            return 1;
        }
        return 0;
    }
public:
    int maxDistance(vector<int>& position, int m) {
        int n = position.size();
        sort(position.begin(),position.end());

        int l = 1, r=position[n-1];
        int ans = 1;
        while(l<=r){
            int mid = l+(r-l)/2;
            if(h(position, mid, m)){
                ans = mid;
                l=mid+1;
            }
            else{
                r = mid-1;
            }
        }
        return ans;
    }
};