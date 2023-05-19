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
    int backtrack(vector<int>& nums, int mask, int pairsPicked, vector<int>& memo) {
        if (2 * pairsPicked == nums.size()) {
            return 0;
        }
        if (memo[mask] != -1) {
            return memo[mask];
        }

        int maxScore = 0;
        for (int firstIndex = 0; firstIndex < nums.size(); ++firstIndex) {
            for (int secondIndex = firstIndex + 1; secondIndex < nums.size(); ++secondIndex) {
                if (((mask >> firstIndex) & 1) == 1 or ((mask >> secondIndex) & 1) == 1) {
                    continue;
                }
                int newMask = mask | (1 << firstIndex) | ((1 << secondIndex));
                int currScore = (pairsPicked + 1) * __gcd(nums[firstIndex], nums[secondIndex]);
                int remainingScore = backtrack(nums, newMask, pairsPicked + 1, memo);
                maxScore = max(maxScore, currScore + remainingScore);
            }
        }
        memo[mask] = maxScore;
        return maxScore;
    }

    int maxScore(vector<int>& nums) {
        int memoSize = 1 << nums.size();
        vector<int> memo(memoSize, -1);
        return backtrack(nums, 0, 0, memo);
    }
};