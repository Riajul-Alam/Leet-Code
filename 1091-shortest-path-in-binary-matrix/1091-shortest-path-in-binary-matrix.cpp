#define pb push_back
#define ff first
#define ss second
#define vi vector<int>
#define vl vector<ll>
#define vvi vector<vi>
#define vvl vector<vl>
#define pii pair<int,int>
#define pll pair<ll,ll>
#define all(v) (v).begin(), (v).end()
#define rall(v) (v).rbegin(), (v).rend()
#define sz(cont) (int)(cont).size()
class Solution {
public:
    // Grid direction array [8]
    int X[8] = {-1,1,0,0,-1,1,-1,1};
    int Y[8] = {0,0,-1,1,1,1,-1,-1};
    bool valid(int x,int y,int n,vvi &grid,vvi &dist,int dis){
        return (x>=0 && x<n && y>=0 && y<n && grid[x][y]==0 && dis+1<dist[x][y]);
    }
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        queue<pair<int,pii>>q;
        int n,m;n=sz(grid);m=sz(grid[0]);
        vvi dist(n,vi(m,1e9));
        dist[0][0]=0;
        if(grid[0][0]==0){
            if(n==1)return 1;
            q.push({0,{0,0}});
        }
        while(!q.empty())
        {
            auto u=q.front();q.pop();
            int dis,x,y;
            dis=u.ff;
            x=u.ss.ff;
            y=u.ss.ss;
            for(int i=0;i<8;i++){
                int nr,nc;
                nr=X[i]+x;
                nc=Y[i]+y;
                if(valid(nr,nc,n,grid,dist,dis)){
                    dist[nr][nc]=dis+1;
                    if(nr==n-1 && nc==n-1){
                        return dis+2;
                    }
                    q.push({dis+1,{nr,nc}});
                }
            }
        }
        return -1;
    }
};