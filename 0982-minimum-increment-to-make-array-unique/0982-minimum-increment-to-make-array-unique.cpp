class Solution {
public:
    int minIncrementForUnique(vector<int>& nums) {
        vector<int> v(200001,0);
        
        int res = 0;
        for(int i=0;i<nums.size();i++){
            if(v[nums[i]]==0){
                v[nums[i]]=1;
            }
            else{
                int j = nums[i];
                while(v[j]!=0){
                    j++;
                }
                v[j]=1;
                res+=abs(nums[i]-j);
            }
        }
        return res;
    }
};