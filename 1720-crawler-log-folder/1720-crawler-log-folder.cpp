class Solution {
public:
    int minOperations(vector<string>& logs) {
        int ans = 0;
        for(auto s: logs){
            if(s == "./"){
                // I remain in the same folder
                continue;
            }
            else if(s == "../"){
                ans = ans -1;
                ans = max(ans, 0);
            }
            else ans++;
        }
        return ans;
    }
};