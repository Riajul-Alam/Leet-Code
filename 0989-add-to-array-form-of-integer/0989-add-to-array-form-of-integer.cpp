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
class Solution {
public:
    vector<int> addToArrayForm(vector<int>& num, int k) {
       int n=sz(num);
        string s,ans;s=tostr(k);
        int m=sz(s);
        ll l=n-1,r=m-1,carry=0;
        while(l>=0 && r>=0){
            int tm;
            tm=(s[r]-'0')+num[l]+carry;
            ans+=((tm%10)+'0');carry=0;
            if(tm>=10){
                tm/=10;
                carry=tm%10;
            }
            l--,r--;
        }
        while(l>=0){
            int tm;
            tm=num[l]+carry;carry=0;
            ans+=((tm%10)+'0');
            if(tm>=10){
                tm/=10;
                carry=tm%10;
            }
            l--;
        }
        while(r>=0){
            int tm;
            tm=(s[r]-'0')+carry;
            ans+=((tm%10)+'0');carry=0;
            if(tm>=10){
                tm/=10;
                carry=tm%10;
            }
            r--;
        }
        while(carry){
            ans+=((carry%10)+'0');
            carry/=10;
        }
        vector<int>res;
        for(int i=sz(ans)-1;i>=0;i--){
            res.pb(ans[i]-'0');
        }
        return res;
    }
};