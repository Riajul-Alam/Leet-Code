//Bismillahir Rahmanir Raheem
#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;
#define pb push_back
#define ff first
#define ss second
#define vi vector<int>
#define vl vector<ll>
#define vvi vector<vi>
#define vvl vector<vl>
#define pii pair<int,int>
#define pll pair<ll,ll>

#define all(v) (v).begin(), (v).end()
#define rall(v) (v).rbegin(), (v).rend()
#define sz(cont) (int)(cont).size()
class Solution {
public:
    map<pii,int>mp;
    int ans=0;
    void dfs(int node,vvi &g,vi &vis){
        vis[node]=1;
        for(auto q:g[node]){
            if(!vis[q]){
                if(mp[{node,q}]>0){
                    ans++;
                }
                dfs(q,g,vis);
            }
        }
    }
    int minReorder(int n, vector<vector<int>>& c) {
        int m=sz(c);ans=0;
        vvi g(n+5);
        vi vis(n+5,0);
        for(int i=0;i<m;i++){
            g[c[i][0]].pb(c[i][1]);
            g[c[i][1]].pb(c[i][0]);
            mp[{c[i][0],c[i][1]}]++;
        }
        dfs(0,g,vis);
        return ans;
    }
};
