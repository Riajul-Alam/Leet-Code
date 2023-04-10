#define ll long long int
#define vvb vector<vector<bool>>
#define vvl vector<vector<int>>
#define vb  vector<bool>

// Grid direction array [4]
int X[4]={0,0,-1,1};
int Y[4]={1,-1,0,0};
class Solution {
public:

    bool valid(int x,int y,int nx,int my,vvb &visited){
      return (x>=0 && x<nx && y>=0 && y<my && !visited[x][y]);
    }

    int dfs(int x,int y,vvb &visited,vector<vector<int>>&a,int n,int m){
      if(visited[x][y] || a[x][y]==0){
        return 0;
      }
      int ans=1;
      visited[x][y]=1;
      for(int i=0;i<4;i++)
      {
        int nx=X[i]+x;
        int my=Y[i]+y;
        if(valid(nx,my,n,m,visited)){
          ans+=dfs(nx,my,visited,a,n,m);
        }
      }
      return ans;
    }
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int n,m;n=grid.size(),m=grid[0].size();
        int ans=0;
        vvb vis(n+5,vb(m+5,0));
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(!vis[i][j]){
                    ans=max(ans,dfs(i,j,vis,grid,n,m));
                }
            }
        }
        return ans;
    }
};