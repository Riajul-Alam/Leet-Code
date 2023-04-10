class Solution {
public:
    vector<int> sortArray(vector<int>& nums) {
        multiset<int>val;
        for(auto q:nums)val.insert(q);
        nums.clear();
        for(auto q:val)nums.push_back(q);
        return nums;
    }
};