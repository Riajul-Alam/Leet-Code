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
#define vpl vector<pll>
#define vpls vector<pair<ll,string>
#define vpsl vector<pair<string,ll>>

#define f0(b) for(int i=0;i<(b);i++)
#define f00(b) for(int j=0;j<(b);j++)
#define f1(i,l,r) for(int i=l;i<r;i++)
#define rf1(i,r,l) for(int i=r-1;i>=l;i--)
#define f2(i,l,r) for(int i=l;i<=r;i++)
#define rf2(i,r,l) for(int i=r;i>=l;i--)
#define print1(x) cout<<x<<endl;
#define print2(x,y) cout<<x<<" "<<y<<endl;
#define print3(x,y,z) cout<<x<<" "<<y<<" "<<z<<endl;

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
#define debug(x) cout << #x <<" "; _print(x); cout << endl;
#define bug2(x,y) cout<<#x<<" "<<#y<<endl; _print(x);cout<<" ";_print(y);cout<<endl;
#define bug3(x,y,z) cout<<#x<<" "<<#y<<" "<<#z<<endl; _print(x);cout<<" ";_print(y);cout<<" ";_print(z);cout<<endl;
void _print(ll t) {cout << t;}
void _print(int t) {cout << t;}void _print(string t) {cout << t;}
void _print(char t) {cout << t;}void _print(lld t) {cout << t;}
void _print(double t) {cout << t;}void _print(ull t) {cout << t;}
template <class T, class V> void _print(pair <T, V> p) {cout << "{"; _print(p.ff); cout << ","; _print(p.ss); cout << "}";}
template <class T> void _print(vector <T> v) {cout << "[ "; for (T i : v) {_print(i); cout << " ";} cout << "]";}
template <class T>void _print(vector<vector<T>> &v){cout << "[ ";for (auto i : v){_print(i);}cout << " ]";}
template <class T> void _print(set <T> v) {cout << "[ "; for (T i : v) {_print(i); cout << " ";} cout << "]";}
template <class T> void _print(multiset <T> v) {cout << "[ "; for (T i : v) {_print(i); cout << " ";} cout << "]";}
template <class T, class V> void _print(map <T, V> v) {cout << "[ "; for (auto i : v) {_print(i); cout << " ";} cout << "]";}
template <class T,class V> void printpair(vector<pair<T,V>>p){for(auto q:p)cout<<q.ff<<" "<<q.ss<<endl;}
template <class T> void print(vector<T>v){for (T i : v) {cout<<i<<" ";}cout<<endl;}
const ll mod = 1e9 + 7;
#define eps 1e-10
#define INF 1e8
#define vvb vector<vector<bool>>
#define vb  vector<bool>

class Solution {
public:

    // Grid direction array [4]
    int X[4]={0,0,-1,1};
    int Y[4]={1,-1,0,0};

    bool valid(int x,int y,int nx,int my,vvb &visited,vvi & g){
      return (x>=0 && x<nx && y>=0 && y<my && !visited[x][y] && g[x][y]==1);
    }
    vector<pii>b;
    void dfs(int x,int y,vvb &visited,vector<vi>&a,int n,int m){
      if(visited[x][y]){
        return;
      }
      b.pb({x,y});
      int ans=1;
      visited[x][y]=1;
      for(int i=0;i<4;i++)
      {
        int nx=X[i]+x;
        int my=Y[i]+y;
        if(valid(nx,my,n,m,visited,a)){
          dfs(nx,my,visited,a,n,m);
        }
      }
    }
    int shortestBridge(vector<vector<int>>& grid) {
        int n=sz(grid);
        vvb vis(n+5,vb(n+5,0));
        vector<vector<pii>>a;
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(vis[i][j]==0 && grid[i][j]==1){
                    dfs(i,j,vis,grid,n,n);
                    a.pb(b);b.clear();
                }
            }
        }
        int ans=1e9;
        for(int i=0;i<sz(a[0]);i++){
            for(int j=0;j<sz(a[1]);j++){
                ans=min(ans,max(0,abs(a[0][i].ff-a[1][j].ff)+abs(a[0][i].ss-a[1][j].ss)-1));
            }
        }
        return ans;
    }
};







