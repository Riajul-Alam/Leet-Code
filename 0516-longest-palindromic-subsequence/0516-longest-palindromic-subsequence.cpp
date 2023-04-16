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
    int f(int l,int r,string &s,vector<vector<ll>>&dp)
    {
      if(l==r)return 1;
      if(l>r)return 0;
      if(dp[l][r]!=-1)return dp[l][r];
      int x=0,y=0,z=0;
      if(s[l]==s[r]){
        return dp[l][r]=2+f(l+1,r-1,s,dp);
      }
      return dp[l][r]=max(f(l+1,r,s,dp),f(l,r-1,s,dp));
    }
    int longestPalindromeSubseq(string s) {
        ll n,m,k,x,y,z,sum=0,c1=0,c2=0,ans=0;
        n=sz(s);
        vector<vector<ll>>dp(n,vector<ll>(n,-1));
        return f(0,n-1,s,dp);
    }
};