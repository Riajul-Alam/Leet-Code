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
#define vpl vector<pll>
#define f0(b) for(int i=0;i<(b);i++)
#define f00(b) for(int j=0;j<(b);j++)
#define all(v) (v).begin(), (v).end()
#define rall(v) (v).rbegin(), (v).rend()
#define sz(cont) (int)(cont).size()
#define toll(a) atoll(a.c_str())
string tostr(ll a) {stringstream rr;rr<<a;return rr.str();}
#define fast ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
const ll mod = 1e9 + 7;
#define eps 1e-10
#define INF 1e18
class Solution {
public:
    vector<ll>dp;
    int low,high,zero,one;
    ll f(int i)
    {
        if(i>high)return 0;
        ll &ans=dp[i];
        if(ans!=-1)return ans%mod;
        ans=0;
        if(i>=low && i<=high)ans=1;
        ans=((ans%mod)+(f(i+one)%mod))%mod;
        ans=((ans%mod)+(f(i+zero)%mod))%mod;
        return ans;
    }
    int countGoodStrings(int low, int high, int zero, int one) {
        this->low=low;this->high=high;this->zero=zero;this->one=one;
        dp.assign(100005,-1);
        return f(0);
    }
};






