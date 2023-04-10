//Bismillahir Rahmanir Raheem
#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;
#define pb push_back
#define ff first
#define ss second
#define in insert
#define vi vector<int>
#define vl vector<ll>
#define vvi vector<vi>
#define vvl vector<vl>
#define pii pair<int,int>
#define pll pair<ll,ll>
#define print1(x) cout<<x<<endl;
#define print2(x,y) cout<<x<<" "<<y<<endl;
#define print3(x,y,z) cout<<x<<" "<<y<<" "<<z<<endl;
#define all(v) (v).begin(), (v).end()
#define rall(v) (v).rbegin(), (v).rend()
#define sz(cont) (int)(cont).size()
#define mem(a,b) memset(a,b,sizeof(a))
#define toll(a) atoll(a.c_str())
string tostr(int a) {stringstream rr;rr<<a;return rr.str();}
#define fast ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
const ll mod = 1e9 + 7;
#define eps 1e-10
#define INF 2e9
class Solution {
public:
    ll ans=0;
    int dfs(int node,vvi &g,vi &vis,int seat){
        vis[node]=1;
        
        int Count=1;
        for(auto q:g[node]){
            if(!vis[q]){
                Count+=dfs(q,g,vis,seat);
            }
        }
        int car=Count/seat;
        if(Count%seat)car++;
        if(node==0)return 0;
        ans+=car;
        return Count;
        
    }
    long long minimumFuelCost(vector<vector<int>>& roads, int seats) {
        int n=sz(roads)+1;
        vector<vector<int>>g(n+5);
        for(int i=0;i<sz(roads);i++){
            g[roads[i][0]].pb(roads[i][1]);
            g[roads[i][1]].pb(roads[i][0]);
        }
        vector<int>vis(n+5,0);
        int tmp=dfs(0,g,vis,seats);
        return ans;
    }
};