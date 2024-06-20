class Solution {
public:
    int longestCommonSubsequence(string text1, string text2) {
        int n = text1.size(), m= text2.size();
        vector<vector<int>> dp(n, vector<int>(m,0));
        bool f1 = 0, f2 = 0;
        for(int i=0;i<n;i++){
            if(text1[i]==text2[0]){
                f1=1;
            }
            if(f1==0)dp[i][0]=0;
            else dp[i][0]=1;
        }
        for(int i=0;i<m;i++){
            if(text2[i]==text1[0]){
                f2=1;
            }
            if(f2==0)dp[0][i]=0;
            else dp[0][i]=1;
        }

        for(int i=1;i<n;i++){
            for(int j=1;j<m;j++){
                if(text1[i]==text2[j]){
                    dp[i][j]=1+dp[i-1][j-1];
                }
                else{
                    dp[i][j]=max(dp[i-1][j], dp[i][j-1]);
                }
            }
        }
        return dp[n-1][m-1];
    }
};