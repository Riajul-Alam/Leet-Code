//Bismillahir Rahmanir Raheem
#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;
typedef unsigned long long ull;
typedef long double lld; 
#define pb push_back
#define ff first
#define ss second
#define all(v) (v).begin(), (v).end()
#define rall(v) (v).rbegin(), (v).rend()
#define sz(cont) (int)(cont).size()

class Solution {
public:
    unordered_map<string,bool>dp;
    bool f(string s1,string s2)
    {
        if(sz(s1)==1)return s1==s2;
        if(s1==s2)return 1;
        int n=sz(s1);
        string cur=s1+s2;
        if(dp.find(cur)!=dp.end())return dp[cur];
        for(int i=1;i<n;i++){
            bool x=f(s1.substr(0,i),s2.substr(0,i))&&f(s1.substr(i),s2.substr(i));
            bool y=f(s1.substr(0,i),s2.substr(n-i))&&f(s1.substr(i),s2.substr(0,n-i));
            if(x || y){return dp[cur]=true;}
        }
        return dp[cur]=false;;
    }
    bool isScramble(string s1, string s2) {
        int n=sz(s1);
        return f(s1,s2);
    }
};