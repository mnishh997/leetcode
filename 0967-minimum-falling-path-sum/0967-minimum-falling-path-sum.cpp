class Solution {
public:
    int minFallingPathSum(vector<vector<int>>& matrix) {
        int n = matrix.size();
        int m= matrix[0].size();

        vector<vector<int>> dp(n, vector<int>(m,0));

        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(i==0){
                    dp[i][j]=matrix[i][j];
                }
                else{
                    int down = 1e9, dr=1e9, dl = 1e9;
                    down = dp[i-1][j]+matrix[i][j];
                    if(j-1>=0)dr=dp[i-1][j-1]+matrix[i][j];
                    if(j+1<n){
                        dl = dp[i-1][j+1]+matrix[i][j];
                    }
                    dp[i][j]=min(down, min(dr,dl));
                }
            }
        }
        int ans = INT_MAX;
        for(int i=0;i<m;i++){
            ans = min(ans, dp[n-1][i]);
        }
        return ans;
    }
};