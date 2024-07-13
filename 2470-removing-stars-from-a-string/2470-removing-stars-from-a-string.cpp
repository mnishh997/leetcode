class Solution {
public:
    string removeStars(string s) {
        int i = 0;
        int n = s.size();
        vector<bool> take(n, true);
        stack<int> st;
        while(i<s.size()){
            if(s[i] != '*'){
                st.push(i);
            }
            else{
                take[i] = false;
                take[st.top()]=false;
                st.pop();
            }
            i++;
        }
        string res= "";
        for(int i=0;i<n;i++){
            if(take[i] == true)res+=s[i];
        }return res;
    }
};