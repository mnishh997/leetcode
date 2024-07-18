class Solution {
public:
    string shortestCommonSupersequence(string s, string t) {
        // first get the lcs
        int n = s.size(), m = t.size();
        vector<vector<int>> dp(n+1, vector<int>(m+1, 0));
        for(int i=1;i<n+1;i++){
            for(int j=1;j<m+1;j++){
                if(s[i-1] == t[j-1]){
                    dp[i][j] = dp[i-1][j-1]+1;
                }
                else{
                    dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
                }
            }
        }
        int i = n, j = m;
        string lcs = "";
        while(dp[i][j]!=0){
            if(s[i-1] == t[j-1]){
                lcs += s[i-1];
                j--;
                i--;
            }
            else{
                if(dp[i-1][j]>dp[i][j-1]){
                    i--;
                }
                else j--;
            }
        }

        reverse(lcs.begin(), lcs.end());
        int ind = 0;string res = "";
        int q = 0, p = 0;
        while(ind<lcs.size()){
            while(s[p]!=lcs[ind]){
                res+=s[p];
                p++;
            }
            while(t[q]!=lcs[ind]){
                res+=t[q];
                q++;
            }
            res+=lcs[ind];
            ind++;
            p++;
            q++;
        }
        while(p<s.size()){
            res+=s[p];p++;

        }
        while(q<t.size()){
            res+=t[q];
            q++;
        }
        return res;
    }
};