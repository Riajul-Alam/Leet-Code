//Bismillahir Rahmanir Raheem
#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;
#define pb push_back
#define ff first
#define ss second
class Solution {
public:
    string frequencySort(string s) {
        map<char,int>mp;
        for(int i=0;i<s.size();i++){
            mp[s[i]]++;
        }
        string ans;
        vector<pair<int,string>>vp;
        for(auto q:mp){
            int x=q.second;ans="";
            for(int i=0;i<x;i++)ans+=q.first;
            if(ans.size()>0){
                vp.push_back({x,ans});
            }
        }
        sort(vp.rbegin(),vp.rend());ans="";
        for(int i=0;i<vp.size();i++){
            ans+=vp[i].second;
        }
        return ans;
    }
};