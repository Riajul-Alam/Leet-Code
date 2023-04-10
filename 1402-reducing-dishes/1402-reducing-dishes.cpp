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
#define all(v) (v).begin(), (v).end()
#define rall(v) (v).rbegin(), (v).rend()
#define sz(cont) (int)(cont).size()

class Solution {
public:
    int f(int i,int Count,vvi &dp,vi &a){
        if(i>=sz(a)){
            return 0;
        }
        if(dp[i][Count]!=-1){
            return dp[i][Count];
        }
        int x=0,y=0;
        x=(a[i]*Count)+f(i+1,Count+1,dp,a);
        y=f(i+1,Count,dp,a);
        return dp[i][Count]=max(x,y);
    }
    int maxSatisfaction(vector<int>& a) {
        int n=sz(a);sort(all(a));
        vvi dp(n,vi(n+1,-1));
        return f(0,1,dp,a);
    }
};














