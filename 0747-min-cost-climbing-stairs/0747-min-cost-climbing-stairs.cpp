class Solution {
public:
    int minCostClimbingStairs(vector<int>& cost) {
        int n = cost.size();
        if(n == 1) return cost[0];
        if(n == 2) return min(cost[0], cost[1]);

        int a = cost[1], b = cost[0], c = 0;
        for(int i=2;i<n;i++) {
            c = min(a, b) + cost[i];
            b = a, a = c;
        }
        return min(a, b);
    }
};