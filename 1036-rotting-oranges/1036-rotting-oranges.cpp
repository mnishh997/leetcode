class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        queue<pair<int,int>> q;
        int temp =0;
        for(int i=0;i<grid.size();i++){
            for(int j=0;j<grid[i].size();j++){
                if(grid[i][j]==2)q.push({i,j});
                else if(grid[i][j]==1)temp++;
            }
        }
        int ans = 0;
        while(!q.empty()){
            int sz = q.size();
            bool f = 0;
            for(int k=0;k<sz;k++){
                int i = q.front().first;
                int j = q.front().second;
                q.pop();
                if(i-1>=0){
                    if(grid[i-1][j]==1){
                        q.push({i-1, j});
                        grid[i-1][j]=2;
                        f=1;
                        temp--;
                    }
                }
                if(i+1<m){
                    if(grid[i+1][j]==1){
                        q.push({i+1, j});
                        grid[i+1][j]=2;
                        f=1;
                        temp--;
                    }
                }
                if(j+1<n){
                    if(grid[i][j+1]==1){
                        q.push({i, j+1});
                        grid[i][j+1]=2;
                        f=1;
                        temp--;
                    }
                }
                if(j-1>=0){
                    if(grid[i][j-1]==1){
                        q.push({i, j-1});
                        grid[i][j-1]=2;
                        f=1;
                        temp--;
                    }
                }
            }
            if(f==1)ans++;
        }
        if(temp!=0)ans=-1;
        return ans;
    }
};