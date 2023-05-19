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
    int numWays(vector<string>& words, string target) {
        const int alphabet = 26;
        const int mod = 1000000007;
        int m = target.size(), k = words[0].size();
        vector cnt(alphabet, vector<int>(k));
        for (int j = 0; j < k; j++) {
            for (const string& word : words) {
                cnt[word[j] - 'a'][j]++;
            }
        }
        vector dp(m + 1, vector<long long>(k + 1, -1));
        
        function<long long(int, int)> f = [&](int i, int j) -> long long {
            if (j == 0) {
                return i == 0 ? 1 : 0;
            }
            if (dp[i][j] != -1) {
                return dp[i][j];
            }
            dp[i][j] = f(i, j - 1);
            if (i > 0) {
                dp[i][j] += cnt[target[i - 1] - 'a'][j - 1] * f(i - 1, j - 1);
            }
            dp[i][j] %= mod;
            return dp[i][j];
        };
        
        return f(m, k);
    }
};