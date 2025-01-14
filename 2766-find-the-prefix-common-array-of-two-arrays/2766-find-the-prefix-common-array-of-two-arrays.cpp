class Solution {
public:
    vector<int> findThePrefixCommonArray(vector<int>& A, vector<int>& B) {
        vector<int> res;
        set<int> s;
        int prev = 0;
        for(int i=0;i<A.size();i++) {
            int sz = s.size();
            s.insert(A[i]);s.insert(B[i]);
            if(s.size()-sz == 2) {
                res.push_back(prev);
            }
            else if(s.size()-sz == 1) {
                prev+=1;
                res.push_back(prev);
            }
            else {
                prev+=2;
                res.push_back(prev);
            }
        }
        return res;
    }
};