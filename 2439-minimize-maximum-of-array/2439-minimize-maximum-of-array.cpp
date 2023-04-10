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
    bool good(vector<ll>a,ll mid)
    {
        ll n=sz(a);
        ll cur=0,mx=0;
        for(int i=n-1;i>=0;i--)
        {
            a[i]+=cur;cur=0;
            if(a[i]>mid){
                cur+=(a[i]-mid);a[i]=mid;
            }
        }
        return a[0]+cur<=mid;
        
    }
    int minimizeArrayValue(vector<int>&a) {
        ll mx=0,n=sz(a);
        vector<ll>b(n);
        for(ll i=0;i<n;i++)
        {
            b[i]=a[i];
            mx=max(ll(a[i]),mx);
        }
        ll l=-1,r=mx+1;
        while(l+1<r){
            ll mid=(l+r)/2;
            if(good(b,mid)){
                r=mid;
            }else l=mid;
        }
        return int(r);
    }
};