#define ll long long int
#define vvb vector<vector<bool>>
#define vb  vector<bool>

// Grid direction array [4]
ll X[4]={0,0,-1,1};
ll Y[4]={1,-1,0,0};
// Grid direction array [8]
ll X8[8]={0,0,1,-1,-1,1,1,-1};
ll Y8[8]={1,-1,0,0,-1,-1,1,1};
// Bishop direction array [8]
ll BX[8]={0,0,1,-1,-1,1,1,-1};
ll BY[8]={1,-1,0,0,-1,-1,1,1};
// Knight Direction Array
ll KX[8] = {1,1,2,2,-1,-1,-2,-2};
ll KY[8] = {2,-2,1,-1,2,-2,1,-1};

class Solution {
public:
    bool valid(ll x,ll y,ll nx,ll my,vvb &visited,vector<vector<char>>&a){
      return (x>=0 && x<nx && y>=0 && y<my && !visited[x][y] && a[x][y]=='1');
    }

    ll dfs(ll x,ll y,vvb &visited,vector<vector<char>>&a,ll n,ll m){
      if(visited[x][y] || a[x][y]=='0'){
        return 0;
      }
      visited[x][y]=1;
      for(int i=0;i<4;i++)
      {
        ll nx=X[i]+x;
        ll my=Y[i]+y;
        if(valid(nx,my,n,m,visited,a)){
          dfs(nx,my,visited,a,n,m);
        }
      }
      return 1;
    }
    int numIslands(vector<vector<char>>& grid) {
        vvb vis(grid.size()+5,vector<bool>(grid[0].size()+5,0));
        int ans=0;
        for(int i=0;i<grid.size();i++){
            for(int j=0;j<grid[i].size();j++){
                ans+=dfs(i,j,vis,grid,grid.size(),grid[0].size());
            }
        }
        return ans;
        
    }
};

