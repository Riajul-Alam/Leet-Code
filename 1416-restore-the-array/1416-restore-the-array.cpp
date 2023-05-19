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
ll dp[100001];
ll solve(string &s,ll k,int pos)
{
    if(pos==s.length()) return 1;
    if(dp[pos]!=-1) return dp[pos];
    
    ll ans=0;

    ll x=0;
    for(int i=pos;i<s.length();i++)
    {
        x=(x*10)+(s[i]-'0');
        if(x<=k && x>=1ll)
        {
            ans=(ans+solve(s,k,i+1))%mod;
        }
        else break;
    }
    return dp[pos]=ans;
}
class Solution {
public:
    int numberOfArrays(string s, int k) {
        memset(dp,-1,sizeof(dp));
        return solve(s,k,0);
        
    }
};








