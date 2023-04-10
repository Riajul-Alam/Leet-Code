typedef long long int ll;
#define pb push_back
#define ff first
#define ss second
#define sz(cont) (int)(cont).size()
class Solution {
public:
    vector<vector<int>>dp;
    int f(int i,vector<pair<int,int>>&a,int last){
        if(i>=a.size())return 0;
        if(dp[i][last]!=-1)return dp[i][last];
        int x=0,y=0;
        if(i+1<a.size()){
            x=f(i+1,a,last);
        }
        if(a[last].ff<=a[i].ff && a[i].ss>=a[last].ss){
            y=a[i].ss+f(i+1,a,i);
        }else{
            y=f(i+1,a,last);
        }
        return dp[i][last]=max(x,y);
    }
    int bestTeamScore(vector<int>& scores, vector<int>& ages) {
        int n=scores.size();
        dp=vector<vector<int>>(n+5,vector<int>(n+5,-1));
        vector<pair<int,int>>vp;
        vp.pb({0,0});
        for(int i=0;i<n;i++){
            vp.pb({ages[i],scores[i]});
        }
        sort(vp.begin(),vp.end());
        return f(0,vp,0);
    }
};