#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;
#define pb push_back
#define ff first
#define ss second
class Solution {
public:
    int missingNumber(vector<int>& nums) {
        map<int,int>mp;
        for(int i=0;i<nums.size();i++){
            mp[nums[i]]++;
        }
        for(int i=0;i<=nums.size();i++)
        {
            if(mp[i]==0)return i; 
        }
        return 0;
    }
};