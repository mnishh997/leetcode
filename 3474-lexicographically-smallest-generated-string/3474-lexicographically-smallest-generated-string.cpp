class Solution {
public:
    string generateString(string str1, string str2) {
        int n = str1.size(), m = str2.size();
        string s(n + m - 1, 'a');
        for(int i=0;i<n;i++) {
            if(str1[i] == 'T') {
                for(int j=i;j<i+m;j++) {
                    s[j] = str2[j-i];
                }
            }
        }
        for(int i=0;i<n;i++) {
            if(str1[i] == 'T') {
                if(s.substr(i, m) != str2) {
                    return "";
                }
            }
        }
        for(int i=0;i<n;i++) {
            if(str1[i] == 'F') {
                if(s.substr(i, m) == str2) {
                    bool changed = false;
                    for(int j=i;j<min(n, i+m);j++) {
                        if(str1[j] == 'T') {
                            s[j-1] = 'b';
                            changed = true;
                            break;
                        }
                    }
                    if(!changed) {
                        s[i+m-1] = 'b';
                    }
                }
            }
        }
        for(int i=0;i<n;i++) {
            if(str1[i] == 'T') {
                if(s.substr(i, m) != str2) {

                    // cout<<s;
                    return "";
                }
            }
        }
        return s;
    }
};