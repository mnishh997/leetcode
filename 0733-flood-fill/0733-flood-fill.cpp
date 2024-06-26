class Solution {
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        int m = image.size(), n = image[0].size();
        vector<vector<int>> vis(m, vector<int>(n, 0));
        queue<pair<int,int>> q;
        q.push({sr,sc});
        int temp = image[sr][sc];
        image[sr][sc]=color;
        vis[sr][sc]=1;
        
        while(!q.empty()){
            int i = q.front().first;
            int j = q.front().second;
            q.pop();
            if(i-1>=0){
                if(vis[i-1][j]==0 && image[i-1][j]==temp){
                    vis[i-1][j]=1;
                    q.push({i-1,j});
                    image[i-1][j]=color;
                }
            }
            if(j-1>=0){
                if(vis[i][j-1]==0 && image[i][j-1]==temp){
                    vis[i][j-1]=1;
                    q.push({i,j-1});
                    image[i][j-1]=color;
                }
            }  
            if(i+1<m){
                if(vis[i+1][j]==0 && image[i+1][j]==temp){
                    vis[i+1][j]=1;
                    q.push({i+1,j});
                    image[i+1][j]=color;
                }
            }  
            if(j+1<n){
                if(vis[i][j+1]==0 && image[i][j+1]==temp){
                    vis[i][j+1]=1;
                    q.push({i,j+1});
                    image[i][j+1]=color;
                }
            }   
        }
        return image;
    }
};