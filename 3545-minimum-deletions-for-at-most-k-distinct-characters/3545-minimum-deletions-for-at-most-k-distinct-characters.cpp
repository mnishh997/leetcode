class Solution {
public:
    int minDeletion(string s, int k) {
        vector<int> count(26, 0);
        for(int i=0;i<s.size();i++) {
            count[s[i] - 'a']++;
        }
        sort(count.begin(), count.end(), greater<int>());
        int n = s.size();
        int aux = 0;
        for(int i=0;i<k;i++) {
            aux += count[i];
        }
        return n - aux;
    }
};