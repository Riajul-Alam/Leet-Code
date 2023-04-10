class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        map<int,int>mp;
        for(int i=0;i<nums.size();i++){
            mp[nums[i]]++;
        }
        cout<<nums.size()<<endl;
        return nums.size()!=mp.size();
    }
};