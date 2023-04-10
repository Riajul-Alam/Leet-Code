//Bismillahir Rahmanir Raheem
#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;
typedef unsigned long long ull;
typedef long double lld; 
#define pb push_back
#define ff first
#define ss second
#define vi vector<int>
#define vl vector<ll>
#define vvi vector<vi>
#define vvl vector<vl>
#define all(v) (v).begin(), (v).end()
#define rall(v) (v).rbegin(), (v).rend()
#define sz(cont) (int)(cont).size()
const ll mod = 1e9 + 7;
#define eps 1e-10
#define INF 1e8

class Solution {
public:
    int dfs(int n,int m,int k,int i,int j,vector<vector<vector<int>>>&dp,vvi &pre)
    {
        if(pre[i][j]==0)return 0;
        if(k==0)return 1;
        if(dp[k][i][j]!=-1)return dp[k][i][j];
        int ans=0;
        for(int ii=i+1;ii<n;ii++){
            if(pre[i][j]-pre[ii][j]>0){
                ans=(ans+dfs(n,m,k-1,ii,j,dp,pre))%mod;
            }
        }
        for(int ii=j+1;ii<m;ii++){
            if(pre[i][j]-pre[i][ii]>0){
                ans=(ans+dfs(n,m,k-1,i,ii,dp,pre))%mod;
            }
        }
        return dp[k][i][j]=ans;
    }
    int ways(vector<string>& pizza, int k) {
        int n=sz(pizza),m=sz(pizza[0]);
        vector<vector<vector<int>>>dp(k,vvi (n,vi(m,-1)));
        vvi pre(n+5,vi(m+5,0));
        for(int i=n-1;i>=0;i--){
            for(int j=m-1;j>=0;j--){
                pre[i][j]=pre[i][j+1]+pre[i+1][j]-pre[i+1][j+1]+(pizza[i][j]=='A'?1:0);  
            }
        }
        return dfs(n,m,k-1,0,0,dp,pre);
    }
};