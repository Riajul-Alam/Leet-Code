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
    bool check(char c){
        return c=='a'||c=='e'||c=='i'||c=='o'||c=='u';
    }
public:
    int maxVowels(string s, int k) {
        int n=sz(s),ans=0;
        vector<int>freq(28,0);
        int l=0;
        for(int r=0;r<n;r++){
            freq[s[r]-'a']++;
            while(l<n && l<=r && (r-l+1>k || !check(s[l]))){
                freq[s[l]-'a']--;l++;
            }
            if(r-l+1<=k){
                int Count=0;
                for(int i=0;i<26;i++){
                    if(check(char(i+'a')))Count+=freq[i];
                }
                ans=max(ans,Count);
            }
        }
        return ans;
    }
};









