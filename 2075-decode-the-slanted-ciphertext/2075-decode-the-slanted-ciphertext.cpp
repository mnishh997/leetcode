class Solution {
public:
    string decodeCiphertext(string encodedText, int rows) {
        if(!encodedText.size())return "";
        int cols = (encodedText.size()/rows);
        string res = "";
        int i = 0;
        vector<int> vis(encodedText.size(), 0);
        while(i<vis.size() && !vis[i]) {
            int j = i;
            while(j<encodedText.size()) {
                res+=encodedText[j];
                vis[j] = 1;
                j+=cols+1;
            }
            i++;
        }
        
        while(res.back() == ' ') res.pop_back();
        return res;
    }
};