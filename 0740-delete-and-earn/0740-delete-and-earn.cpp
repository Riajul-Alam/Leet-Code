#define ff first
#define ss second
#define pb push_back
#define sz(a) (int)a.size()
class Solution {
public:
	int dp[20005][2];
	int f(int i,int j,int n,vector<pair<int,int>>& cost,int val)
	{
		if(i>=n)return 0;
        //if(val==cost[i].ff)return f(i+1,n,cost,cost[i].ff);
		if(dp[i][j]!=-1)return dp[i][j];
		//dp[i]=0;
		int x=0,y=0,z=0;
        if(val==cost[i].ff)z=f(i+1,0,n,cost,cost[i].ff);
        else{
            y=cost[i].ss+f(i+1,1,n,cost,cost[i].ff+1);
            x=f(i+1,0,n,cost,val);
        }
        dp[i][j]=max({x,y,z});
		return dp[i][j];
	}
    int deleteAndEarn(vector<int>& cost) {
    	map<int,int>mp;
    	for(int i=0;i<cost.size();i++){
    		mp[cost[i]]++;
    		for(int j=0;j<2;j++)dp[i][j]=-1;
    	}
    	vector<pair<int,int>>frq;
    	for(auto q:mp){
    		frq.pb({q.ff,(q.ss*q.ff)});
    	}
    	int x=0,y=0;
    	x=f(0,0,sz(frq),frq,0);
    	return x;
    }
};