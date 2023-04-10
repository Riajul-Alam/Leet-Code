class Solution {
public:
    long long distinctNames(vector<string>& ideas) {
        unordered_map<string,int>mp;
        for(int i=0;i<ideas.size();i++){
            mp[ideas[i]]++;
        }
        vector<vector<int>>dp(26,vector<int>(26,0));
        for(int i=0;i<ideas.size();i++){
            string cur=ideas[i];
            char ch1=cur[0];
            for(int j=0;j<26;j++){
                char ch2=j+'a';
                cur[0]=ch2;
                if(mp.find(cur)==mp.end()){
                    dp[ch1-'a'][j]++;
                }
            }
        }
        long long int ans=0;
        for(int i=0;i<26;i++){
            for(int j=0;j<26;j++){
                ans+=(dp[i][j]*dp[j][i]);
            }
        }
        return ans;
    }
};