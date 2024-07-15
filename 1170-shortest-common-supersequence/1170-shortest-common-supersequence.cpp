class Solution {
public:
    string shortestCommonSupersequence(string str1, string str2) {
        // first try to find the longest common subsequence
        int n = str1.size(), m = str2.size();
        vector<vector<int>> dp(n+1, vector<int>(m+1, 0));
        

        for(int i=1;i<n+1;i++){
            for(int j=1;j<=m;j++){
                if(str1[i-1] == str2[j-1])dp[i][j] = dp[i-1][j-1] + 1;

                else{
                    dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
                }
            }
        }
        // dp[n][m] gives the lengeth of longest common subsequence
        //let us now get the lcs 
        int i = n, j = m;
        string lcs = "";
        while(dp[i][j] != 0){
            if(str1[i-1] == str2[j-1]){
                lcs+=str1[i-1];
                j--;i--;
            }
            else{
                if(dp[i-1][j] > dp[i][j-1])i--;
                else j--;
            }
        }

        reverse(lcs.begin(), lcs.end());
        //return lcs;
        // ind will traverse on res string
        if(lcs.size() == 0)return str1+str2;

        int ind = 0;
        int p = 0, q = 0;
        string res ="";
        while(ind<lcs.size()){
            while(str1[p]!=lcs[ind]){
                res+=str1[p];
                p++;
            }
            while(str2[q] != lcs[ind]){
                res+=str2[q];
                q++;
            }
            res+=lcs[ind];
            ind++;
            p++;
            q++;
        }
        while(p<str1.size()){
            res+=str1[p];
            p++;
        }
        while(q<str2.size()){
            res+=str2[q];
            q++;
        }
        return res;
    }
};