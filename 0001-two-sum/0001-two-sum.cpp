//Bismillahir Rahmanir Raheem
#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;
#define pb push_back
#define ff first
#define ss second
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        int n=nums.size();
        int ind1=0,ind2=0;
        vector<int>ans;
        int c1=0;
        for(int i=0;i<n;i++){
           for(int j=0;j<n;j++){
               if(i==j)continue;
               if(nums[i]+nums[j]==target){
                   if(i>j)swap(i,j);
                   ans.push_back(i);
                   ans.push_back(j);c1++;break;
               }
           }
           if(c1)break;
        }
        return ans;

    }
};