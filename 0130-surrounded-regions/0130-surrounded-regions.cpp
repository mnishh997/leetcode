class Solution {
public:
    void solve(vector<vector<char>>& board) {
        int n = board.size();
        int m = board[0].size();
        queue<pair<int,int>> q;
        vector<vector<char>> res(n, vector<char>(m,'X'));
        for(int i=0;i<n;i++){
            if(board[i][0]=='O'){
                q.push({i,0}  );
                res[i][0]='O';
            }
            if(board[i][m-1]=='O'){
                q.push({i,m-1});
                res[i][m-1]='O';
            }
        }
        for(int i=0;i<m;i++){
            if(board[0][i]=='O'){
                q.push({0, i});
                res[0][i]='O';
            }
            if(board[n-1][i]=='O'){
                q.push({n-1, i});
                res[n-1][i]='O';
            }
        }
        

        while(!q.empty()){
            int i = q.front().first;
            int j = q.front().second;

            q.pop();

            if(i-1>=0){
                if(board[i-1][j]=='O' && res[i-1][j]=='X'){
                    q.push({i-1,j});
                    res[i-1][j]='O';
                }
            }
            if(i+1<n){
                if(board[i+1][j]=='O' && res[i+1][j]=='X'){
                    q.push({i+1,j});
                    res[i+1][j]='O';
                }
            }
            if(j-1>=0){
                if(board[i][j-1]=='O' && res[i][j-1]=='X'){
                    q.push({i,j-1});
                    res[i][j-1]='O';
                }
            }
            if(j+1<m){
                if(board[i][j+1]=='O' && res[i][j+1]=='X'){
                    q.push({i,j+1});
                    res[i][j+1]='O';
                }
            }
        }
        board = res;
    }
};
