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
class Solution2 {
public:
    int partitionString(string s) {
        map<char,int>mp;int ans=0;
        for(int i=0;i<sz(s);i++){
            if(mp[s[i]]){
                mp.clear();mp[s[i]]++;ans++;
            }else mp[s[i]]++;
        }
        return ans+1;
    }
};
class Solution {
public:
    int partitionString(string s) {
        int mp[30]={};int ans=0;
        for(int i=0;i<sz(s);i++){
            if(mp[s[i]-'a']){
                for(int j=0;j<30;j++){
                    mp[j]=0;
                }
                mp[s[i]-'a']++;ans++;
            }else mp[s[i]-'a']++;
        }
        return ans+1;
    }
};