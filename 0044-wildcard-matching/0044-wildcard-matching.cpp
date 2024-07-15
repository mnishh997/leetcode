class Solution {
    bool isAllStars(string s, int k){
        for(int i=0;i<k;i++){
            if(s[i] != '*')return false;
        }
        return true;

    }
public:
    bool isMatch(string s, string p) {
        int n = s.size(), m = p.size();
        vector<vector<bool>> dp(n+1, vector<bool> (m+1,0));
        dp[0][0]= true;
        for(int i=1;i<n+1;i++)dp[i][0]=false;

        for(int i=0;i<m+1;i++){
            dp[0][i] = isAllStars(p, i);
        }
        for(int i=1;i<n+1;i++){
            for(int j=1;j<m+1;j++){
                if(s[i-1] == p[j-1] || p[j-1]=='?'){
                    dp[i][j] = dp[i-1][j-1]&1;
                }
                else{
                    if(p[j-1] =='*'){
                        dp[i][j] = dp[i-1][j]|dp[i][j-1];
                    }
                    else{
                        dp[i][j] = 0;
                    }
                }
            }
        }
        return dp[n][m];
        
    }
};