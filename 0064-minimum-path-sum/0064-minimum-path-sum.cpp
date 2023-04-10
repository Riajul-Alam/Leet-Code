class Solution {
public:
    int dp[200][200],n,m;
    int fun(int i,int j,vector<vector<int>>& grid){
        if(i>=n || j>=m){
            return 1e9;
        }
        if(i==n-1 && j==m-1)return grid[i][j];
        if(dp[i][j]!=-1)return dp[i][j];
        int x=grid[i][j],y=grid[i][j];
        x+=fun(i+1,j,grid);
        y+=fun(i,j+1,grid);
        return dp[i][j]=min(x,y);
    }
    int minPathSum(vector<vector<int>>& grid) {
        memset(dp,-1,sizeof(dp));
        n=grid.size();m=grid[0].size();
        return fun(0,0,grid);
    }
};