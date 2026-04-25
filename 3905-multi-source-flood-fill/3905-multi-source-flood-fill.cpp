class Solution {
public:
    vector<vector<int>> colorGrid(int n, int m, vector<vector<int>>& sources) {
        vector<vector<int>> color(n, vector<int> (m, 0));
        vector<vector<int>> time(n, vector<int>(m, -1));
        queue<pair<int, pair<int, int>>> q; // color, i, j
        for(int i=0;i<sources.size();i++) {
            int x = sources[i][0], y = sources[i][1], c = sources[i][2];
            q.push(make_pair(c, make_pair(x, y)));
            color[x][y] = c;
            time[x][y] = 0;
        }
        int dx[4] = {0, -1, 1, 0};
        int dy[4] = {-1, 0, 0, 1};
        while(!q.empty()) {
            int c = q.front().first, i = q.front().second.first, j = q.front().second.second;
            q.pop();
            if(c != color[i][j]) {
                continue;
            }
            for(int k=0;k<4;k++) {
                int ni = i + dx[k], nj = j + dy[k];
                if(ni>=0 && ni<n && nj>=0 && nj<m && (time[ni][nj] == -1 || time[ni][nj] == time[i][j] + 1)) {
                    if(color[ni][nj] < color[i][j]) {
                        q.push(make_pair(color[i][j], make_pair(ni, nj)));
                        color[ni][nj] = color[i][j];
                        time[ni][nj] = time[i][j] + 1;
                    }
                }
            }
        }
        return color;
    }
};