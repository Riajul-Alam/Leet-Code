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
ll modInverse(ll a,ll b)
{
    ll ans= 1;
    while (b) {
 
        if(b&1) { //right most bit set or not 
            ans=(ans*a)%mod;
        }
        a=(a*a)%mod;
        b >>= 1;// right shift 1 ,basically divide by 2
    }
    return ans;
}  
inline ll MOD(ll a){ return (a%mod + mod) %mod ; }
inline ll modAdd(ll a,ll b){ return MOD( MOD(a) + MOD(b) ) ; }
inline ll modSub(ll a,ll b){ return MOD( MOD(a) - MOD(b) ) ; }
inline ll modMul(ll a,ll b){ return MOD( MOD(a) * MOD(b) ) ; }
inline ll modInv(ll a){ return modInverse(a,mod-2) ; }
inline ll modDiv(ll a,ll b){return modMul(a,modInv(b));}
class Solution {
public:
    int binarySearchRightmost(vector<int>&nums, int target) {
        int left = 0, right = nums.size() - 1;
        while (left <= right) {
            int mid = left + (right - left) / 2;
            if (nums[mid] <= target) {
                left = mid + 1;
            } else {
                right = mid - 1;
            }
        }
        return left;
    }
    
    int numSubseq(vector<int>&nums, int target) {
        int n = nums.size();
        sort(all(nums));
        vector<int>power(n,0);
        power[0] = 1;
        for (int i = 1; i < n; ++i) {
            power[i] = (power[i - 1] * 2) % mod;
        }
        int answer = 0;
        for (int left = 0; left < n; left++) {
            int right = binarySearchRightmost(nums, target - nums[left]) - 1;
            if (right >= left) {
                answer += power[right - left];
                answer %= mod;
            }
            
        }
        return answer;
    }
};
