class Solution {
public:
    int searchInsert(vector<int>&n, int t) {
        int i=lower_bound(n.begin(),n.end(),t)-n.begin();
        return i;
    }
};