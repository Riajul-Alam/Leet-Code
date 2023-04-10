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
        if(valid(nx,my,n,m,visited)&& a[nx][my]==1){
          ans+=dfs(nx,my,visited,a,n,m);
        }
      }
      return ans;
    }
    int numEnclaves(vector<vector<int>>& grid) {
        int n,m;n=grid.size(),m=grid[0].size();
        int ans=0,c1;
        vvb vis(n+5,vb(m+5,0));
        for(int i=0;i<m;i++){
            if(!vis[0][i]){
                 c1=dfs(0,i,vis,grid,n,m);
            }
            if(!vis[n-1][i]){
                c1=dfs(n-1,i,vis,grid,n,m);
            }
        }
        for(int i=0;i<n;i++){
            if(!vis[i][0]){
                 c1=dfs(i,0,vis,grid,n,m);
            }
            if(!vis[i][m-1]){
                c1=dfs(i,m-1,vis,grid,n,m);
            }
        }
        for(int i=1;i<n-1;i++){
            for(int j=1;j<m-1;j++){
                if(!vis[i][j]){
                    ans+=dfs(i,j,vis,grid,n,m);
                }
            }
        }
        return ans;
    }
};