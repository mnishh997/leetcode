class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        int n = mat.size();
        int m = mat[0].size();
        queue<pair<int,int>> q;
        vector<vector<int>> res(n,vector<int>(m,1e9));
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(mat[i][j]==0){
                    q.push({i,j});
                    res[i][j]=0;
                }
            }
        }
        while(!q.empty()){
            int i = q.front().first;
            int j = q.front().second;
            q.pop();
            int temp = res[i][j]+1;
            if(i-1>=0){
                if(temp<res[i-1][j]){
                    q.push({i-1,j});
                    res[i-1][j]=temp;
                }
            }
            if(i+1<n){
                if(temp<res[i+1][j]){
                    q.push({i+1,j});
                    res[i+1][j]=temp;
                }
            }
            if(j-1>=0){
                if(temp<res[i][j-1]){
                    q.push({i,j-1});
                    res[i][j-1]=temp;
                }
            }
            if(j+1<m){
                if(temp<res[i][j+1]){
                    q.push({i,j+1});
                    res[i][j+1]=temp;
                }
            }
        }
        return res;

    }
};