class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        vector<int>final;k=k%nums.size();
        for(int i=nums.size()-k;i<nums.size();i++)final.push_back(nums[i]);
        for(int i=0;i<nums.size()-k;i++)final.push_back(nums[i]);
        nums=final;
    }
};