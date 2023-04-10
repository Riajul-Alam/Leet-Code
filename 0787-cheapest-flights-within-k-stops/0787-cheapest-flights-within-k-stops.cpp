const int INF=1e8;
class Solution {
public:
    vector<vector<int>>dp,cost;
    int kk;
    int f(int node, int k, int dst,vector<vector<int>>&g)
    {
        if (k>kk+1)return INF;
        if (node == dst){return 0;}
        if (dp[node][k] != -1){return dp[node][k];}
        int ans = INF;
        for (auto i : g[node]){
            ans = min(ans, cost[node][i] + f(i,k+1,dst,g));
        }
        return dp[node][k] = ans;
    }
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        vector<vector<int>>g(n);cost.resize(n+5,vector<int>(n+5,0));
        for (auto e:flights){
            g[e[0]].push_back(e[1]);
            cost[e[0]][e[1]]=e[2];
        }
        dp.resize(n+5,vector<int>(n+5,-1));
        kk=k;
        int ans=f(src,0,dst,g);
        return ans==INF?-1:ans;
    }
};
















