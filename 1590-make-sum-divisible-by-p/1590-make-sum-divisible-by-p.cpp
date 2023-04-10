class Solution {
public:
    int minSubarray(vector<int>& nums, int p) {
        long long sum=0,mod=0;
        for(int i=0;i<nums.size();i++){
            mod=(mod+nums[i])%p;
        }
        if(mod==0)return 0;
        int ans=1e9;
        map<int,int>mp;mp[0]=-1;sum=0;
        for(int i=0;i<nums.size();i++){
            sum=(sum+nums[i])%p;
            mp[sum]=i;
            int tmp=(sum-mod+p)%p;
            if(mp.count(tmp)){
                ans=min(ans,i-mp[tmp]);
            }
        }
        if(ans==1e9 || ans>=nums.size())ans=-1;
        return ans;
    }
};