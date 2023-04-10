class Solution {
public:
    set<vector<int>>final;
    void dfs(int i,vector<int>&a,vector<int>ans){
        if(i>=a.size())return;
        if(ans.size()==0){
            dfs(i+1,a,ans);
            ans.push_back(a[i]);
            dfs(i+1,a,ans);
        }
        else if(ans.size()){
            if(ans.back()<=a[i]){
                dfs(i+1,a,ans);
                ans.push_back(a[i]);
                if(ans.size()>=2)final.insert(ans);
                dfs(i+1,a,ans);
            }else{
               dfs(i+1,a,ans); 
            }
        }
    }
    vector<vector<int>> findSubsequences(vector<int>& nums) {
        vector<int>ans;
        dfs(0,nums,ans);
        vector<vector<int>>result(final.size());
        int j=0;
        for(auto q:final){
            for(auto p:q){
                result[j].push_back(p);
            }j++;
        }
        return result;
    }
};