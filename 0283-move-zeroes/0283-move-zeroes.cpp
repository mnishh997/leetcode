class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        queue<int> q;
        for(int i=0;i<nums.size();i++) {
            if(nums[i] == 0) {
                q.push(i);
            }
            else {
                if(q.size()>0) {
                    int idx = q.front();
                    q.pop();
                    swap(nums[i], nums[idx]);
                    q.push(i);
                }
            }
        }
        
    }
};