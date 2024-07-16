class Solution {
public:
    int singleNumber(vector<int>& nums) {
        vector<int> v(32, 0);
        for(int k=0;k<32;k++){
            for(int i=0;i<nums.size();i++){
                v[k] += nums[i]&1;
                v[k] = v[k]%3;
                nums[i] = nums[i]>>1;
            }
        }
        int res = 0;
        for(int i=0;i<32;i++){
            if(v[i] == 1){
                res = res|(1<<i);
            }
        }  
        return res;
    }
};