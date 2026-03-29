class Solution {
    vector<int> getDivisors(int n) {
        vector<int> divisors;
        int limit = sqrt(n) + 1;
        for(int i=2;i<limit;i++) {
            if(n%i == 0) {
                divisors.push_back(i);
                if(n/i != i)divisors.push_back(n/i);
            }
        }
        return divisors;
    }

    void buildTree1(int idx, int l, int r, vector<int>& segTree, vector<int>& nums) {
        if(l == r) {
            segTree[idx] = nums[l];
            return;
        }
        int mid = (l + r)>>1;
        buildTree1(2*idx + 1, l, mid, segTree, nums);
        buildTree1(2*idx + 2, mid + 1, r, segTree, nums);
        segTree[idx] = min(segTree[2*idx + 1], segTree[2*idx + 2]);
        return;
    }

    void buildTree2(int idx, int l, int r, vector<int>& segTree, vector<int>& nums) {
        if(l == r) {
            segTree[idx] = nums[l];
            return;
        }
        int mid = (l + r)>>1;
        buildTree2(2*idx + 1, l, mid, segTree, nums);
        buildTree2(2*idx + 2, mid + 1, r, segTree, nums);
        segTree[idx] = max(segTree[2*idx + 1], segTree[2*idx + 2]);
        return;
    }

    int getMin(int idx, int l, int r, int s, int e, vector<int>& segTree) {
        if(l == s && r == e) {
            return segTree[idx];
        }
        int mid = (l + r)>>1;
        
        if(e <= mid) {
            return getMin(2*idx + 1, l, mid, s, e, segTree);
        }
        else if(s > mid) {
            return getMin(2*idx + 2, mid + 1, r, s, e, segTree);
        }
        else {
            int a = getMin(2*idx + 1, l, mid, s, mid, segTree);
            int b = getMin(2*idx + 2, mid +1, r, mid + 1, e, segTree);
            return min(a, b);
        }
    }

    int getMax(int idx, int l, int r, int s, int e, vector<int>& segTree) {
        if(l == s && r == e) {
            return segTree[idx];
        }
        int mid = (l + r)>>1;
        
        if(e <= mid) {
            return getMax(2*idx + 1, l, mid, s, e, segTree);
        }
        else if(s > mid) {
            return getMax(2*idx + 2, mid + 1, r, s, e, segTree);
        }
        else {
            int a = getMax(2*idx + 1, l, mid, s, mid, segTree);
            int b = getMax(2*idx + 2, mid +1, r, mid + 1, e, segTree);
            return max(a, b);
        }
    }

    bool isCyclicShift(vector<int>& nums, vector<int>& segTreeMin, vector<int>& segTreeMax) {
        int n = nums.size();
        int cnt = 0;
        for(int i=1;i<n;i++) {
            if(nums[i] < nums[i-1]) {
                cnt++;
            }
        }
        if(cnt == 1 && nums[0] >= nums[n-1]) {
            return true;
        }
        return false;
    }

public:
    int sortableIntegers(vector<int>& nums) {
        int n = nums.size();
        if(n == 1) {
            return 1;
        }
        vector<int> divisors = getDivisors(n);

        vector<int> temp = nums;
        sort(temp.begin(), temp.end());
        bool equal = true;
        for(int i=0;i<n;i++) {
            if(temp[i] != nums[i]) {
                equal = false;
                break;
            }
        }
        if(equal) {
            int sum = 0;
            for(auto it: divisors) {
                sum += it;
            }
            return sum + n + 1;
        }

        vector<int> segTreeMin(4*n, 0), segTreeMax(4*n, 0);
        buildTree1(0, 0, n-1, segTreeMin, nums);
        buildTree2(0, 0, n-1, segTreeMax, nums);

        int sum = 0;

        for(auto k: divisors) {
            int prevMax = 0;
            int l = 0, r = k - 1;
            bool possible = true;
            while(possible && r < n) {
                int mini = getMin(0, 0, n-1, l, r, segTreeMin);
                int maxi = getMax(0, 0, n-1, l, r, segTreeMax);
                if(mini >= prevMax) {
                    prevMax = maxi;
                    l = r + 1;
                    r = r + k;
                }
                else {
                    possible = false;
                }
            }
            if(possible) {
                sum += k;
            }
        }
        if(isCyclicShift(nums, segTreeMin, segTreeMax)) {
            sum += n;
        }
        return sum;
    }
};