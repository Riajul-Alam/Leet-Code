class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        long long n=nums.size(),sum=0,ans=0;
        map<int,int>mp;
        for(int i=0;i<n;i++){
          sum+=nums[i];
          if(sum==k){
            ans++;
          }
          if(mp.count(sum-k)){
            ans+=mp[sum-k];
          }
          mp[sum]++;
        }
        return ans;
    }
};