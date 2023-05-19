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

class Solution {
public:
    vector<vector<int>>dp;
    vector<int>a,b;int n,m;
    int f(int l,int r)
    {
      if(l>=n || r>=m)return 0;
      if(dp[l][r]!=-1)return dp[l][r];
      int x=0,y=0,z=0,p=0;
      x=f(l+1,r);
      z=f(l+1,r+1);
      p=f(l,r+1);
      for(int i=r;i<m;i++){
        if(a[l]==b[i]){
          y=1+f(l+1,i+1);break;
        }
      }
      return dp[l][r]=max({x,y,z,p});
    }
    int maxUncrossedLines(vector<int>& a, vector<int>& b) {
      n=sz(a),m=sz(b);
      this->a=a;this->b=b;
      dp.assign(505,vector<int>(505,-1));
      return f(0,0);
    }
};