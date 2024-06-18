class Solution {
public:
    int f(vector<vector<int>>& triangle,int i , int j,int n,vector<vector<int>> &dp){
        if(i==n-1) return triangle[i][j];
        if(dp[i][j]!=-1)return dp[i][j];

        int d= triangle[i][j]+f(triangle,i+1,j,n,dp);
        int dg= triangle[i][j]+f(triangle,i+1,j+1,n,dp);

        dp[i][j]=min(d,dg);

        return dp[i][j];
    }
    int minimumTotal(vector<vector<int>>& triangle) {
        int n=triangle.size();
        vector<vector<int>> dp(n,vector<int>(n,0));
        /*int ans = f(triangle,0,0,n,dp);
        return ans;*/
        for(int i=n-1;i>=0;i--){
            for(int j=0;j<i+1;j++){
                //base case
                if(i==n-1){
                    dp[i][j]=triangle[i][j];
                }
                else{
                    int d=triangle[i][j]+dp[i+1][j];
                    int dg= triangle[i][j]+dp[i+1][j+1];
                    dp[i][j]=min(d,dg);
                }
            }
        }
        return dp[0][0];
    }
};