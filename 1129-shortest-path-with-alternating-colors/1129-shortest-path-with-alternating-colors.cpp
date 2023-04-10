//Bismillahir Rahmanir Raheem
#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;
typedef unsigned long long ull;
typedef long double lld; 
#define pb push_back
#define ff first
#define ss second
#define MP make_pair
#define pf push_front
#define in insert
#define ppb pop_back
#define ppf pop_front
#define nl '\n'
#define sp ' '
#define vi vector<int>
#define vl vector<ll>
#define vvi vector<vi>
#define vvl vector<vl>
#define pii pair<int,int>
#define pll pair<ll,ll>
#define all(v) (v).begin(), (v).end()
#define rall(v) (v).rbegin(), (v).rend()
#define sz(cont) (int)(cont).size()
#define mnv(v) *min_element(v.begin(),v.end())
#define mxv(v) *max_element(v.begin(),v.end())
#define countv(v,a) count(v.begin(),v.end(),a)
#define mem(a,b) memset(a,b,sizeof(a))
#define Find(a,x) find(all(a),x)
#define LB(a,X) lower_bound(all(a),X)-a.begin()
#define UB(a,X) upper_bound(all(a),X)-a.begin()
#define toll(a) atoll(a.c_str())
string tostr(ll a) {stringstream rr;rr<<a;return rr.str();}
#define fast ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
#define eps 1e-10
#define INF 1e18

class Solution {
public:
    vector<int> shortestAlternatingPaths(int n, vector<vector<int>>& redEdges, vector<vector<int>>& blueEdges){
        vector<vector<pll>>g(n);
        for(auto edges:redEdges){
            g[edges[0]].pb({edges[1],0});
        }
        for(auto edges:blueEdges){
            g[edges[0]].pb({edges[1],1});
        }
        queue<pll>q;
        q.push({0LL,0LL});
        q.push({0LL,1LL});
        vector<vector<ll>>dis(n,vector<ll>(2,INF));
        dis[0][0]=0;
        dis[0][1]=0;
        while(!q.empty()){
            int u=q.front().ff;
            int color=q.front().ss;q.pop();
            for(auto cur:g[u]){
                int v=cur.ff;
                int curColor=cur.ss;
                if(dis[v][curColor]==INF && color!=curColor){
                    dis[v][curColor]=dis[u][color]+1;q.push(cur);
                }
            }
        }
        vector<int>res(n,-1);
        for(int i=0;i<n;i++){
            if (dis[i][0] != INF || dis[i][1] != INF)
            {
                res[i] = min(dis[i][0], dis[i][1]);
            }
        }
        return res;
    }
};



