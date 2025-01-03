class Solution {
public:
    int minimumOperations(vector<vector<int>>& grid) {
        int res = 0;
        for(int i=0;i<grid[0].size();i++) {
            for(int j=1;j<grid.size();j++) {
                if(grid[j][i]<=grid[j-1][i]) {
                    res+= abs(grid[j][i]-grid[j-1][i]-1);
                    grid[j][i] = grid[j-1][i]+1;
                }
            }
        }
        return res;
    }
};