class Solution {
public:
    bool primeSubOperation(vector<int>& nums) {
        vector<int> primes(1001, 1);
        for (int i = 2; i * i < 1001; i++) {
            if (primes[i] == true) {
                for (int p = i * i; p < 1001; p += i) {
                    primes[p] = 0;
                }
            }
        }
        vector<int> prime;
        for (int i = 2; i < primes.size(); i++) {
            if (primes[i] == 1) {
                prime.push_back(i);
            }
        }
        int mini = 0;
        for(int i=0;i<nums.size();i++) {
            int l = 0, r = prime.size()-1;
            int least = nums[i];
            while(l<=r) {
                int mid = l+(r-l)/2;
                if(nums[i] - prime[mid] > mini) {
                    least = min(least,nums[i] - prime[mid]);
                    l = mid+1;
                }
                else {
                    r = mid-1;
                }
            }
            if(least > mini) {
                nums[i] = least;
                mini = nums[i];
                
            }
            else {
                return 0;
            }
        }
        return 1;
    }
};