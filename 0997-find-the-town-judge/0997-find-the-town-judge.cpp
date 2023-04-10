class Solution {
public:
    int findJudge(int n, vector<vector<int>>& trust) {
        int freq[n];
        for(int i=0;i<n;i++)freq[i]=0;
        for(int i=0;i<trust.size();i++){
            freq[trust[i][1]-1]++;
        }
        int c1=0,ans=-1;
        for(int i=0;i<n;i++){
            if(freq[i]==n-1){
                ans=i;
            }
        }
        for(int i=0;i<trust.size();i++){
            if(trust[i][0]==ans+1){
                c1++;break;
            }
        }
        if(ans==-1 || c1>0)return -1;
        return ans+1;
    }
};