class Solution {
public:
    int rangeSum(vector<int>& nums, int n, int l, int r) {int m = 1e9+7;
        vector<int> v;
        for(int i=0;i<n;i++){
            long long sum =0;
            for(int j=i;j<n;j++){
                sum+=(nums[j])%m;
                sum = (sum)%m;
                v.push_back(sum);
            }
            
        }
        long long res = 0;
        sort(v.begin(), v.end());
        for(int i=l-1;i<r;i++){
            res+=v[i]%m;
            res=res%m;
        }return res;
    }
};