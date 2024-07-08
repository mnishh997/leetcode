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
    vector<ll> rank, size, parent;
    public:
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
    vector<vector<string>> accountsMerge(vector<vector<string>>& accounts) {
        int n = accounts.size();
        unordered_map<string, int> m;
        DisjointSet ds(n);
        for(int i=0;i<n;i++){
            for(int j=1;j<accounts[i].size();j++){
                if(m[accounts[i][j]]==0) m[accounts[i][j]]= i+1;
                else{
                    ds.union_by_size(i+1, m[accounts[i][j]]);
                }
            }
        }
        vector<string> mergedMail[n];
        for(auto it: m){
            int par = ds.find_par(it.second);
            string mail = it.first;
            mergedMail[par-1].push_back(mail);
        }
        vector<vector<string>> ans;
        for(int i=0;i<n;i++){
            if(mergedMail[i].size() == 0)continue;
            else{
                sort(mergedMail[i].begin(), mergedMail[i].end());
            }
            vector<string> temp;
            temp.push_back(accounts[i][0]);
            for(auto it: mergedMail[i]){
                temp.push_back(it);
            }
            ans.push_back(temp);

        }
        sort(ans.begin(), ans.end());
        return ans;
    }
};