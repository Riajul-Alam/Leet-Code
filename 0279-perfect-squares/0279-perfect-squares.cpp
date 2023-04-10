//Bismillahir Rahmanir Raheem
#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;
#define pb push_back
#define ff first
#define ss second
#define all(v) (v).begin(), (v).end()
#define rall(v) (v).rbegin(), (v).rend()
#define sz(cont) (int)(cont).size()
#define INF 1e8
class Solution {
public:
    int f(int sum,vector<int>&a,vector<int>&dp)
    {
        if(sum==0){
            return 0;
        }
        if(dp[sum]!=-1)return dp[sum];
        int Count=INF;
        for(int j=0;j<a.size();j++)
        {
            if(sum-a[j]>=0){
                Count=min(Count,1+f(sum-a[j],a,dp));
            }
        }
        return dp[sum]=Count;
    }
    int numSquares(int n) {
        vector<int>store;
        int i=1;
        while(i*i<=n){
            store.pb(i*i);i++;
        }
        vector<int>dp(n+5,-1);
        return f(n,store,dp);
    }
};