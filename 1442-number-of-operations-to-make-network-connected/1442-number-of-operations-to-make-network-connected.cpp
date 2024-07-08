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
public:
    int makeConnected(int n, vector<vector<int>>& connections) {
        DisjointSet ds(n);
        int extra = 0;
        for(auto it: connections){
            if(ds.find_par(it[0]) == ds.find_par(it[1]))extra++;
            else{
                ds.union_by_rank(it[0], it[1]);
            }
        }
        int cnt = 0;
        for(int i=0;i<n;i++){
            // s.insert(ds.find_par(i));
            if(ds.parent[i] == i)cnt++;
        }
        int required = cnt-1;
        if(extra>=required)return required;
        return -1;
    }
};