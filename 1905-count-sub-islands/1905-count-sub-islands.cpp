#define ll long long int
#define vvb vector<vector<bool>>
#define vvl vector<vector<int>>
#define vb  vector<bool>
#define sz(cont) (int)(cont).size()

// Grid direction array [4]
int X[4]={0,0,-1,1};
int Y[4]={1,-1,0,0};
class Solution {
public:

    bool valid(int x,int y,int nx,int my,vvb &visited){
      return (x>=0 && x<nx && y>=0 && y<my && !visited[x][y]);
    }

    int dfs(int x,int y,vvb &visited,vvl &a1,vvl &a2,int n,int m,int &flag){
      if(visited[x][y]){
        return 0;
      }
      int ans=1;
      visited[x][y]=1;
      if(!a1[x][y])flag=0;
      for(int i=0;i<4;i++)
      {
        int nx=X[i]+x;
        int my=Y[i]+y;
        if(valid(nx,my,n,m,visited)&& a2[nx][my]==1){
          if(!a1[nx][my])flag=0;
          dfs(nx,my,visited,a1,a2,n,m,flag);
        }
      }
      return ans;
    }
    int countSubIslands(vector<vector<int>>& grid1, vector<vector<int>>& grid2){
        int n,m;n=grid1.size(),m=grid1[0].size();
        int ans=0,c1;
        vvb vis(n+5,vb(m+5,0));
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(!vis[i][j] && grid2[i][j]==1){
                    int flag=1;
                    dfs(i,j,vis,grid1,grid2,n,m,flag);
                    ans+=flag;
                }
            }
        }
        return ans;
    }
};