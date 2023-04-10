typedef long long int ll;
#define pb push_back
#define ff first
#define ss second
#define all(v) (v).begin(), (v).end()
#define rall(v) (v).rbegin(), (v).rend()
#define sz(cont) (int)(cont).size()
class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
        unordered_map<int,int>mp;
        for(auto q:nums){
            mp[q]++;
        }
        for(auto q:mp){
            if(q.ss==1){
                return q.ff;
            }
        }
        return 0;
    }
};