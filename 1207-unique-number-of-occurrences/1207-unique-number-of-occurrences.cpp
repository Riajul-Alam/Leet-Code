//Bismillahir Rahmanir Raheem
#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;
#define pb push_back
#define ff first
#define ss second
class Solution {
public:
    bool uniqueOccurrences(vector<int>& arr) {
        int n=arr.size();
        map<int,int>mp,m;
        for(int i=0;i<n;i++){
            mp[arr[i]]++;
        }
        for(auto q:mp){
            m[q.second]++;
        }
        for(auto q:m){
            if(q.second>1){
                return false;
            }
        }
        return true;

    }
};