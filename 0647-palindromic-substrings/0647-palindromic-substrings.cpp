class Solution {
public:
    int countSubstrings(string s) {
        int res = s.size();
        int i = 0;
        while(i<s.size()) {
            int l = i-1, r = i+1;
            int cnt = 0;
            while(l>=0 && r<s.size() && s[l] == s[r]) {
                cnt++;
                l--;r++;
            }
            l = i, r = i+1;
            while(l>=0 && r<s.size() && s[l] == s[r]) {
                cnt++;
                l--;
                r++;
            }
            res+=cnt;
            i++;
        }
        return res;
    }
};