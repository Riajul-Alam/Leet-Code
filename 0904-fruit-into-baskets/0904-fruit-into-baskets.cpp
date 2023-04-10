class Solution {
public:
    int totalFruit(vector<int>&a) {
        map<int,int>mp;
        int l=0,ans=0;
        for(int i=0;i<a.size();i++){
            mp[a[i]]++;
            while(mp.size()>2){
                mp[a[l]]--;
                if(mp[a[l]]==0){
                    mp.erase(a[l]);
                }
                l++;
            }
            int sum=0;
            for(auto q:mp){
                sum+=q.second;
            }
            ans=max(sum,ans);
        }
        return ans;
    }
};