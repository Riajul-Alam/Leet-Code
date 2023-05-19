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
    vector<vector<int>> findDifference(vector<int>& a,vector<int>&b) {
        int n,m;n=sz(a),m=sz(b);
        map<int,int>mp,mp1;
        for(int i=0;i<n;i++)mp[a[i]]++;
        for(int i=0;i<m;i++)mp1[b[i]]++;
        vector<int>ans1,ans2;
        for(auto q:mp){
            if(mp1.find(q.ff)==mp1.end()){
                ans1.pb(q.ff);
            }
        }
        for(auto q:mp1){
            if(mp.find(q.ff)==mp.end()){
                ans2.pb(q.ff);
            }
        }
        vector<vector<int>>ans;
        ans.pb(ans1);
        ans.pb(ans2);
        return ans;
    }
};






