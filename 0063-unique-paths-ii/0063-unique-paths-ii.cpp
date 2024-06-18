class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& o) {
        if(o[0][0]==1)return 0;
        int m = o.size();
        int n = o[0].size();
        vector<vector<int>> dp(m, vector<int>(n,0));
        dp[0][0]=1;
        for(int i=0;i<m;i++){
            if(o[i][0]!=1)dp[i][0]=1;
            else break;
        }
        for(int i=0;i<n;i++){
            if(o[0][i]!=1)dp[0][i]=1;
            else break;
        }
        for(int i=1;i<m;i++){
            for(int j=1;j<n;j++){
                int down = 0, right = 0;
                if(i-1>=0){
                    down=dp[i-1][j];
                }
                if(j-1>=0)right = dp[i][j-1];
                dp[i][j]=right+down;
                if(o[i][j]==1)dp[i][j]=0;
            }
        }
        return dp[m-1][n-1];
    }
};