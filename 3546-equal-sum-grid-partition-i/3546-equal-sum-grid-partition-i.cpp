class Solution {
public:
    bool canPartitionGrid(vector<vector<int>>& grid) {
        int n = grid.size(), m = grid[0].size();

        vector<long long> vertical(n, 0), horizontal(m, 0);

        long long sum = 0;
        for(int i=0;i<n;i++) {
            for(int j=0;j<m;j++) {
                sum += grid[i][j];
            }
            vertical[i] = sum;
        }

        sum = 0;

        for(int j=0;j<m;j++) {
            for(int i=0;i<n;i++) {
                sum += grid[i][j];
            }
            horizontal[j] = sum;
        }
        
        for(auto it: vertical) {
            if(it*2 == vertical.back()) {
                return true;
            }
        }
        for(auto it: horizontal) {
            if(it*2 == horizontal.back()) {
                return true;
            }
        }

        return false;
    }
};