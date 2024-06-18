class Solution {
public:
    int uniquePaths(int m, int n) {
        vector<vector<int>> dp(m,vector<int>(n,1));
        for(int i=1;i<m;i++){
            for(int j=1;j<n;j++){
                int right = 0, down = 0;
                if(i-1>=0)down = dp[i-1][j];
                if(j-1>=0)right = dp[i][j-1];
                dp[i][j]=down+right;
            }
        }
        return dp[m-1][n-1];
    }
};