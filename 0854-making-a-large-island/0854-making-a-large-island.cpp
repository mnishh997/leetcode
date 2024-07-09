#include<bits/stdc++.h>
#define M 1000000007
#define ll long long 
#define lld long double
#define frr(i,a,b)  for(ll i=a;i>=b;i--)
#define pb push_back
#define popb pop_back
#define mp make_pair
#define all(x) x.begin(), x.end()
#define f first
#define sec second
#define fr(i,a,b) for(ll i=a;i<b;i++) 
#define rep(i,a,b) for(ll i=a;i<=b;i++)
#define sz(a) (int)a.size()
#define ump unordered_map
#define vec(v,n) vector<ll> v(n)
#define cin(v) for(ll&it:v)cin>>it

using namespace std;

class DisjointSet{
    
    public:
    vector<ll> rank, size, parent;
        DisjointSet(ll n){
            rank.resize(n+1, 0);
            size.resize(n+1, 1);
            parent.resize(n+1);
            fr(i,0,n+1){
                parent[i] = i;
            }
        }
        
        ll find_par(ll u){
            if(parent[u] == u)return u;
            
            return parent[u] = find_par(parent[u]);
        }
        void union_by_rank(ll u, ll v){
            ll ulp_u = find_par(u);
            ll ulp_v = find_par(v);
            if(ulp_u == ulp_v)return;
            if(rank[ulp_u] > rank[ulp_v]){
                parent[ulp_v] = ulp_u;
            }
            else if(rank[ulp_u] < rank[ulp_v]){
                parent[ulp_u] = ulp_v;
            }
            else{
                parent[ulp_u] = ulp_v;
                rank[ulp_u]++;
            }
        }
        void union_by_size(ll u, ll v){
            ll ulp_u = find_par(u);
            ll ulp_v = find_par(v);
            if(ulp_u == ulp_v)return;
            if(size[ulp_u] < size[ulp_v]){
                parent[ulp_u] = ulp_v;
                size[ulp_v]+=size[ulp_u];
            }
            else{
                parent[ulp_v] = ulp_u;
                size[ulp_u]+=size[ulp_v];
            }
        }
};

class Solution {
    bool isValid(int x, int y, int n, int m){
        if(x>=0 && x<n && y>=0 && y<m)return true;
        return false;
    }
public:
    int largestIsland(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        DisjointSet ds(n*m);
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j] == 1){
                    int dr[] = {-1, 0, 1, 0};
                    int dc[] = {0, 1, 0, -1};
                    for(int del = 0;del<4;del++){
                        int x = i+dr[del];
                        int y = j+dc[del];
                        if(isValid(x, y, n, m) && grid[x][y]==1){
                            if(ds.find_par(x*m +y) == ds.find_par(i*m+j))continue;
                            else{
                                /**/ds.union_by_size(x*m +y, i*m+j);
                            }
                        }
                    }
                }
            }
        }
        int res = 0;
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j] == 0){
                    vector<int> temp;
                    int aux = 0;
                    int dr[] = {-1, 0, 1, 0};
                    int dc[] = {0, 1, 0, -1};
                    for(int del = 0;del<4;del++){
                        int x = i+dr[del];
                        int y = j+dc[del];
                        if(isValid(x, y, n, m) && grid[x][y]==1){
                            int par = ds.find_par(x*m + y);
                            bool f = 0;
                            for(int k=0;k<temp.size();k++){
                                if(temp[k] == par){
                                    f=1;
                                }
                            }
                            if(f==0){
                                temp.push_back(par);
                            }
                        }
                    }
                    for(int it: temp){
                        aux+= ds.size[ds.find_par(it)];
                    }
                    aux+=1;
                    res= max(res, aux);
                }
            }
        }
        if(res == 0)res = n*m;
        return res;
    }
};