class Solution {

    int mod= 1e9 + 7;
public:
    int numDistinct(string s, string t) {
        // get the lcs and check if it is equal to t or not
        int n = s.size(), m = t.size();
        vector<vector<long long int>> dp(n+1, vector<long long int>(m+1, 0));
        for(int i=0;i<n+1;i++)dp[i][0] = 1;
        for (int i = 1; i <= m; i++) {
            dp[0][i] = 0;
        }
        for(int i=1;i<n+1;i++){
            for(int j=1;j<m+1;j++){
                if(s[i-1] == t[j-1]){
                    dp[i][j] = (dp[i-1][j-1]%mod + dp[i-1][j]%mod)%mod;
                }
                else{
                    dp[i][j] = dp[i-1][j]%mod;
                }
            }
        }
        return dp[n][m];
    }
};