class Solution {
public:
    int subarraysDivByK(vector<int>& nums, int k,int ans=0) {
        vector<int>mp(k+5,0);int sum=0;
        mp[0]=1;
        for(int i=0;i<nums.size();i++){
            sum+=nums[i];
            sum=sum%k;
            if(sum<0)sum+=k;
            ans+=mp[sum];mp[sum]++;
        }
        return ans;
    }
};