class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
      vector<int>a;
        for(int i=0;i<nums.size();i++){
            if(val!=nums[i]){
                a.push_back(nums[i]);
            }
        }
        nums=a;
        return a.size();
    }
};