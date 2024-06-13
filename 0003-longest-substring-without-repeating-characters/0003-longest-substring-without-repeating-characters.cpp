class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        if(s.size()<2)return s.size();
        int l = 0, r = 0;
        int ans = 1;
        set<char> st;
        while(r<s.size()){
            if(st.find(s[r])==st.end()){
                st.insert(s[r]);   
            }
            else{
                while(st.find(s[r])!=st.end()){
                    st.erase(s[l]);
                    l++;
                }
                st.insert(s[r]);
            }
            ans = max(ans, (int)st.size());
            r++;
        }  
        return ans; 
    }
};