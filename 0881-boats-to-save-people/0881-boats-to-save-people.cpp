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
    int numRescueBoats(vector<int>& people, int limit) {
        sort(people.begin(),people.end());
        int ans=0;
        int l=0,r=people.size()-1;
        while(l<r)
        {
            if(people[l]+people[r]<=limit){
                l++,r--;
            }else{
                r--;
            }
            ans++;
        }
        if(l==r)ans++;
        return ans;
    }
};