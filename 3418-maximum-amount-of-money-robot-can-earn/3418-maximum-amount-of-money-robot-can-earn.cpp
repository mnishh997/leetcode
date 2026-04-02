class Solution {
public:
    int maximumAmount(vector<vector<int>>& coins) {
        int n = coins.size(), m = coins[0].size();

        vector<array<int, 3>> prev(m, {0, 0,  0}), curr(m, {0, 0, 0});
        curr[0][0] = coins[0][0];
        for(int j=1;j<m;j++) {
            curr[j][0] = curr[j-1][0] + coins[0][j];
            curr[j][1] = max(curr[j-1][0], curr[j-1][1] + coins[0][j]);
            curr[j][2] = max(curr[j-1][1], curr[j-1][2] + coins[0][j]);
        }


        for(int i=1;i<n;i++) {
            prev.swap(curr);
            curr[0][0] = prev[0][0] + coins[i][0];
            curr[0][1] = max(prev[0][0], prev[0][1] + coins[i][0]);
            curr[0][2] = max(prev[0][1], prev[0][2] + coins[i][0]);

            for(int j=1;j<m;j++) {
                curr[j][0] = max(curr[j-1][0], prev[j][0]) + coins[i][j];
                int neutraliseThisCell = max(curr[j-1][0], prev[j][0]);
                int didntNeutraliseThisCell = max(curr[j-1][1], prev[j][1]) + coins[i][j];
                curr[j][1] = max(neutraliseThisCell, didntNeutraliseThisCell);
                
                neutraliseThisCell = max(curr[j-1][1], prev[j][1]);
                didntNeutraliseThisCell = max(curr[j-1][2], prev[j][2]) + coins[i][j];

                curr[j][2] = max(neutraliseThisCell, didntNeutraliseThisCell);
            }
        }
        return max(curr[m-1][0], max(curr[m-1][1], curr[m-1][2]));
    }
};