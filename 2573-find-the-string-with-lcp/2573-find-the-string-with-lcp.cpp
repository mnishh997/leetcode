class Solution {
public:
    string findTheString(vector<vector<int>>& lcp) {
        int n = lcp.size();
        string s(n, 'a');

        for(int i=1;i<n;i++) {
            char c = 'a';
            vector<bool> canTake(26, true);
            bool done = false;
            for(int j=0;j<i;j++) {
                if(lcp[i][j]) {
                    // take their character
                    s[i] = s[j];
                    j = i + 4;
                    done = true;
                }
                else {
                    // can't take their chara
                    canTake[s[j]-'a'] = false;
                }
            }

            if(!done) {
                int idx = 0;
                while(!canTake[idx])idx++;


                if(idx > 25) {
                    return "";
                }
                s[i] = 'a' + idx;
            }
        }

        // now create lcp of formed string
        vector<vector<int>> myLCP(n, vector<int>(n, 0));

        string a = s;
        reverse(a.begin(), a.end());
        string b = a;
        for(int l=0;l<n;l++) {
            int i = l, j = 0;
            int curr = 0;
            while(i<n && j<n) {
                if(a[i] == b[j]) {
                    myLCP[n-1-i][n-1-j] = curr+1;
                    myLCP[n-1-j][n-1-i] = curr+1;
                    curr++;
                }
                else {
                    curr = 0;
                }
                i++;
                j++;
            }
        }
        
        for(int i=0;i<n;i++) {
            for(int j=0;j<n;j++) {
                if(lcp[i][j] != myLCP[i][j]) {
                    return "";
                }
                // cout<<myLCP[i][j]<<" ";
            }
            cout<<endl;
        }
        return s;
    }
};