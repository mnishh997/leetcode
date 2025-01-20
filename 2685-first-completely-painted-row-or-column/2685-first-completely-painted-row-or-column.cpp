class Solution {
public:
    int firstCompleteIndex(vector<int>& arr, vector<vector<int>>& mat) {
        int m = mat.size(), n = mat[0].size();
        vector<int> row(m, 0), col(n, 0);
        map<int, pair<int,int>> a;
        for(int i=0;i<m;i++) {
            for(int j=0;j<n;j++) {
                a[mat[i][j]] = {i, j};
            }
        }
        for(int i=0;i<arr.size();i++) {
            int num = arr[i];
            int r = a[num].first;
            int c = a[num].second;
            row[r]+=1;
            col[c]+=1;
            if(row[r] == n || col[c] == m) {
                return i;
            }
        }
        return -1;
    }
};