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

class Solution {
public:
    int findSmallestInteger(vector<int>&nums,int val) {
      int n,m,k,x,y,z,sum=0,c1=0,c2=0,ans=0;
      n=nums.size();vector<int>a=nums;
      map<ll,ll>mp,mp1;
      for(int i=0;i<n;i++){
        if(a[i]<0 && abs(a[i])%val!=0){
          a[i]=(a[i]%val)+val;
        }
        else{
          a[i]=abs(a[i])%val;
        }
        ll tmp=a[i];
        if(mp1[a[i]]){
          a[i]=mp1[a[i]];
        }
        while(mp[a[i]]){
          a[i]+=val;
        }
        mp1[tmp]=a[i];
        mp[a[i]]++;
      }
      x=0;
      for(auto q:mp){
        if(q.ff!=x){
          return x;
        }x++;
      }
      return x;
    }
};