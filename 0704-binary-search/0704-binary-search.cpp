class Solution {
public:
    int search(vector<int>& nums, int target) {
        int l=lower_bound(nums.begin(),nums.end(),target)-nums.begin();
        if(l==nums.size()){
            return -1;
        }
        else if(nums[l]!=target){
            return -1;
        }
        return l;
    }
};