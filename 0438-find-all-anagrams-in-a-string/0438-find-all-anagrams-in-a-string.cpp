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
    vector<int> findAnagrams(string s, string p) {
        int n=sz(s),m=sz(p);
        vector<int>mp(26,0),mp1(26,0);
        for(int i=0;i<m;i++)mp[p[i]-'a']++;
        vector<int>res;
        int l=0,r=0;
        while(r<n){
            int len=r-l;
            if(r==0){
                mp1[s[r]-'a']++;r++;
            }
            else if(len==m){
                if(mp==mp1){
                    res.pb(l);
                }
                mp1[s[l]-'a']--;
                l++;
            }
            else if(len<m){
                mp1[s[r]-'a']++;r++;
            }
        }
        if((r-l)==m){
            if(mp==mp1){
                res.pb(l);
            }  
        }
        return res;
    }
};












