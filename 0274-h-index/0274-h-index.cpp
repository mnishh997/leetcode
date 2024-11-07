class Solution {
public:
    int hIndex(vector<int>& citations) {
        sort(citations.begin(), citations.end());
        int size = citations.size();
        int res = 0;
        int i = 0;
        while(size>=res) {
            if(citations[i]>=res) {
                res++;
            }
            else {
                i++;
                size--;
            }
        }
        // if(res == 0)return res;
        return res-1;
    }
};