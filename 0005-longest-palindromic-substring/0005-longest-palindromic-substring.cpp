class Solution {
public:
    string longestPalindrome(string s) {
        int i = 0;
        string res = "";
        while(i<s.size()) {
            int l = i-1, r = i+1;
            string temp = "";
            temp+=s[i];
            while(l>=0 && r<s.size() && s[l]==s[r]) {
                temp = s[l] + temp + s[r];
                l--;
                r++;
            }
            if(temp.size()>res.size())res = temp;
            l = i, r = i+1;
            temp = "";
            while(l>=0 && r<s.size() && s[l]==s[r]) {
                temp = s[l] + temp + s[r];
                l--;r++;
            }
            if(temp.size() > res.size())res = temp;
            i++;
        }
        return res;
    }
};